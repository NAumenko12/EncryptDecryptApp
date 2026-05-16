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
        vector<int64_t> x1 = obrabotat_chisla(baiti_v_chisla(input), ca, p);
        vector<int64_t> x2 = obrabotat_chisla(x1, cb, p);
        return chisla_v_binar(x2);
    }
    vector<int64_t> x3 = obrabotat_chisla(binar_v_chisla(input), da, p);
    vector<int64_t> x4 = obrabotat_chisla(x3, db, p);
    return chisla_v_baiti(x4);
}

vector<uint8_t> obrabotat_shamira(const vector<uint8_t>& input, bool encrypt){
    cout << "\nПараметры Шамира:\n";
    int64_t p = schitat_int64("Введите простое число p: ");
    int64_t ca = schitat_int64("Введите ключ ca: ");
    int64_t cb = schitat_int64("Введите ключ cb: ");
    return zapustit_shamira(input, encrypt, p, ca, cb);
}
