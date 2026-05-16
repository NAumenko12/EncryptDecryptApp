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
        vector<int64_t> encrypted = obrabotat_chisla(baiti_v_chisla(input), public_key, n);
        return chisla_v_binar(encrypted);
    }
    vector<int64_t> decrypted = obrabotat_chisla(binar_v_chisla(input), private_key, n);
    return chisla_v_baiti(decrypted);
}

vector<uint8_t> obrabotat_rsa(const vector<uint8_t>& input, bool encrypt) {
    cout << "\nПараметры RSA:\n";
    int64_t p = schitat_int64("Введите простое число p: ");
    int64_t q = schitat_int64("Введите простое число q: ");
    int64_t public_key = schitat_int64("Введите открытую степень e: ");
    return zapustit_rsa(input, encrypt, p, q, public_key);
}
