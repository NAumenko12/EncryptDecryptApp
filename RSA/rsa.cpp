#include "crypto_utils.h"

vector<uint8_t> zapustit_rsa(const vector<uint8_t>& input, bool encrypt, int64_t p, int64_t q, int64_t public_key){
    if (!is_prime(p) || !is_prime(q)){
        throw runtime_error("p и q должны быть простыми числами.");
    }
    int64_t n = p * q;
    int64_t phi = (p - 1) * (q - 1);
    int64_t private_key = alg_cherez_c(public_key, phi);
    if (private_key == -1 || gcd(public_key, phi) != 1) {
        throw runtime_error("Не удалось подготовить ключи RSA.");
    }
    if (n <= 255){
        throw runtime_error("n должно быть больше 255, чтобы можно было шифровать байты.");
    }
    if (encrypt){
        return rsa_zashifrovat(input, n, public_key);
    }
    return rsa_rasshifrovat(input, n, private_key);
}

vector<uint8_t> obrabotat_rsa(const vector<uint8_t>& input, bool encrypt) {
    vector<uint8_t> result;
    cout << "\nКлюч RSA:\n";
    vector<int64_t> key = schitat_key_iz_faila();
    if (key.size() != 6 || key[0] != 1) {
        throw runtime_error("Некорректный RSA ключ.");
    }
    int64_t n = key[3];
    int64_t public_key = key[4];
    int64_t private_key = key[5];
    if (encrypt) {
        result = rsa_zashifrovat(input, n, public_key);
    } else {
        result = rsa_rasshifrovat(input, n, private_key);
    }
    return result;
}

void obrabotat_rsa_fail_potokom(bool encrypt, const string& input_path, const string& output_path) {
    cout << "\nКлюч RSA:\n";
    vector<int64_t> key = schitat_key_iz_faila();
    if (key.size() != 6 || key[0] != 1) {
        throw runtime_error("Некорректный RSA ключ.");
    }
    int64_t n = key[3];
    int64_t public_key = key[4];
    int64_t private_key = key[5];
    if (n <= 255) {
        throw runtime_error("n должно быть больше 255, чтобы можно было шифровать байты.");
    }
    ifstream input_file(input_path, ios::binary);
    ofstream output_file(output_path, ios::binary);
    if (!input_file || !output_file) {
        throw runtime_error("Не удалось открыть входной или выходной файл.");
    }
    size_t chunk_size = encrypt ? 4096 : 4096 * sizeof(int64_t);
    vector<char> buffer(chunk_size);
    for (input_file.read(buffer.data(), buffer.size()); input_file.gcount() > 0; input_file.read(buffer.data(), buffer.size())) {
        streamsize read_count = input_file.gcount();
        if (!encrypt && read_count % sizeof(int64_t) != 0) {
            throw runtime_error("Размер RSA шифротекста некорректен.");
        }
        vector<uint8_t> chunk(buffer.begin(), buffer.begin() + read_count);
        vector<uint8_t> result;
        if (encrypt) {
            result = rsa_zashifrovat(chunk, n, public_key);
        } else {
            result = rsa_rasshifrovat(chunk, n, private_key);
        }
        output_file.write(reinterpret_cast<const char*>(result.data()), static_cast<streamsize>(result.size()));
    }
    cout << "Файл обработан потоково.\n";
}
