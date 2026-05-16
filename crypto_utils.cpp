#include "crypto_utils.h"

int64_t mod(int64_t base, int64_t power, int64_t modulo){
    int64_t result = 1;
    base %= modulo;
    while (power > 0){
        if (power % 2 == 1){
            result = (result * base) % modulo;
        }
        base = (base * base) % modulo;
        power /= 2;
    }
    return result;
}

int64_t gcd(int64_t a, int64_t b){
    while (b != 0) {
        int64_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool is_prime(int64_t x){
    bool is_prime_value = true;
    if (x < 2) {
        is_prime_value = false;
    } else {
        for (int64_t i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                is_prime_value = false;
            }
        }
    }
    return is_prime_value;
}

int64_t alg_cherez_c(int64_t base, int64_t module) {
    int64_t r0 = module;
    int64_t r1 = base;
    int64_t u0 = 0;
    int64_t u1 = 1;
    while (r1 != 0){
        int64_t q = r0 / r1;
        int64_t nr = r0 - q * r1;
        int64_t nu = u0 - q * u1;
        r0 = r1;
        r1 = nr;
        u0 = u1;
        u1 = nu;
    }
    if (r0 != 1){
        cout << "Обратного элемента не существует" << endl;
        return -1;
    }
    while (u0 < 0){
        u0 += module;
    }
    return u0;
}
