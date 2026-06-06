#include "../crypto_utils.h"

vector<uint8_t> sgenerirovat_rsa_key() {
    int64_t p = random_prime(257, 5000);
    int64_t q = random_prime(257, 5000);
    for (int attempt = 0; attempt < 100 && p == q; attempt++) {
        q = random_prime(257, 5000);
    }
    if (p == q) {
        throw runtime_error("Не удалось сгенерировать разные p и q.");
    }
    int64_t n = p * q;
    int64_t phi = (p - 1) * (q - 1);
    int64_t public_key = 65537;
    if (public_key >= phi || gcd(public_key, phi) != 1) {
        public_key = random_coprime(phi);
    }
    int64_t private_key = alg_cherez_c(public_key, phi);
    if (private_key == -1) {
        throw runtime_error("Не удалось сгенерировать RSA ключ.");
    }
    cout << "RSA ключ сгенерирован.\n";
    cout << "p = " << p << "\n";
    cout << "q = " << q << "\n";
    cout << "n = " << n << "\n";
    cout << "public_key = " << public_key << "\n";
    cout << "private_key = " << private_key << "\n";
    vector<int64_t> key = {1, p, q, n, public_key, private_key};
    return chisla_v_binar(key);
}
