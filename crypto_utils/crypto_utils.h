#ifndef CRYPTO_MATH_UTILS_H
#define CRYPTO_MATH_UTILS_H

#include <cstdint>

int64_t mod(int64_t base, int64_t power, int64_t modulo);
int64_t gcd(int64_t a, int64_t b);
bool is_prime(int64_t x);
int64_t alg_cherez_c(int64_t base, int64_t module);

#endif
