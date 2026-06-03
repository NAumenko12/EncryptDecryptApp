#include "../crypto_utils.h"

int64_t random_chislo(int64_t min_value, int64_t max_value) {
    random_device device;
    mt19937_64 generator(device());
    uniform_int_distribution<int64_t> distribution(min_value, max_value);
    return distribution(generator);
}

int64_t random_prime(int64_t min_value, int64_t max_value) {
    int64_t value = 0;
    bool found = false;
    for (int attempt = 0; attempt < 1000 && !found; attempt++) {
        value = random_chislo(min_value, max_value);
        found = is_prime(value);
    }
    if (!found) {
        throw runtime_error("Не удалось сгенерировать простое число.");
    }
    return value;
}

int64_t random_coprime(int64_t module) {
    int64_t value = 0;
    bool found = false;
    for (int attempt = 0; attempt < 1000 && !found; attempt++) {
        value = random_chislo(2, module - 1);
        found = gcd(value, module) == 1;
    }
    if (!found) {
        throw runtime_error("Не удалось сгенерировать взаимно простой ключ.");
    }
    return value;
}

vector<uint8_t> sgenerirovat_key(int algorithm) {
    vector<uint8_t> key;
    if (algorithm == 1) {
        key = sgenerirovat_rsa_key();
    } else {
        key = sgenerirovat_shamir_key();
    }
    return key;
}
