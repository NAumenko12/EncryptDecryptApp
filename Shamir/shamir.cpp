#include "crypto_utils.h"

vector<uint8_t> zapustit_shamira(const vector<uint8_t>& input, bool encrypt, int64_t p, int64_t ca, int64_t cb) {
    if (!is_prime(p)){
        throw runtime_error("p должно быть простым числом.");
    }
    if (p <= 255){
        throw runtime_error("p должно быть больше 255, чтобы можно было шифровать байты.");
    }
    int64_t da = alg_cherez_c(ca, p - 1);
    int64_t db = alg_cherez_c(cb, p - 1);
    if (da == -1 || db == -1) {
        throw runtime_error("Не удалось подготовить ключи Шамира.");
    }
    if (encrypt){
        return shamir_zashifrovat(input, p, ca, cb);
    }
    return shamir_rasshifrovat(input, p, da, db);
}

vector<uint8_t> obrabotat_shamira(const vector<uint8_t>& input, bool encrypt){
    vector<uint8_t> result;
    cout << "\nКлюч Шамира:\n";
    vector<int64_t> key = schitat_key_iz_faila();
    if (key.size() != 6 || key[0] != 2) {
        throw runtime_error("Некорректный ключ Шамира.");
    }
    int64_t p = key[1];
    int64_t ca = key[2];
    int64_t cb = key[3];
    int64_t da = key[4];
    int64_t db = key[5];
    if (encrypt) {
        result = shamir_zashifrovat(input, p, ca, cb);
    } else {
        result = shamir_rasshifrovat(input, p, da, db);
    }

    return result;
}

void obrabotat_shamira_fail_potokom(bool encrypt, const string& input_path, const string& output_path) {
    cout << "\nКлюч Шамира:\n";
    vector<int64_t> key = schitat_key_iz_faila();
    if (key.size() != 6 || key[0] != 2) {
        throw runtime_error("Некорректный ключ Шамира.");
    }
    int64_t p = key[1];
    int64_t ca = key[2];
    int64_t cb = key[3];
    int64_t da = key[4];
    int64_t db = key[5];
    if (p <= 255) {
        throw runtime_error("p должно быть больше 255, чтобы можно было шифровать байты.");
    }
    if (da == -1 || db == -1) {
        throw runtime_error("Не удалось подготовить ключи Шамира.");
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
            throw runtime_error("Размер шифротекста Шамира некорректен.");
        }
        vector<uint8_t> chunk(buffer.begin(), buffer.begin() + read_count);
        vector<uint8_t> result;
        if (encrypt) {
            result = shamir_zashifrovat(chunk, p, ca, cb);
        } else {
            result = shamir_rasshifrovat(chunk, p, da, db);
        }
        output_file.write(reinterpret_cast<const char*>(result.data()), static_cast<streamsize>(result.size()));
    }
    cout << "Файл обработан потоково.\n";
}
