#include "../crypto_utils.h"

vector<uint8_t> sgenerirovat_shamir_key() {
    int64_t p = random_prime(257, 5000);
    int64_t ca = random_coprime(p - 1);
    int64_t cb = random_coprime(p - 1);
    int64_t da = alg_cherez_c(ca, p - 1);
    int64_t db = alg_cherez_c(cb, p - 1);
    if (da == -1 || db == -1) {
        throw runtime_error("Не удалось сгенерировать ключ Шамира.");
    }
    cout << "Ключ Шамира сгенерирован.\n";
    cout << "p = " << p << "\n";
    cout << "ca = " << ca << "\n";
    cout << "cb = " << cb << "\n";
    cout << "da = " << da << "\n";
    cout << "db = " << db << "\n";
    vector<int64_t> key = {2, p, ca, cb, da, db};
    return chisla_v_binar(key);
}
