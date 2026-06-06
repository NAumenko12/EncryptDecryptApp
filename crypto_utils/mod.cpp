#include "../crypto_utils.h"

int64_t mod(int64_t base, int64_t power, int64_t modulo) {
    int64_t result = 1;
    base %= modulo;
    while (power > 0) {
        if (power % 2 == 1) {
            result = (result * base) % modulo;
        }
        base = (base * base) % modulo;
        power /= 2;
    }
    return result;
}
