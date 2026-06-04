#include "crypto_utils.h"

void ochistit_chisla(vector<int64_t>& numbers) {
    volatile int64_t* data = numbers.data();
    for (size_t i = 0; i < numbers.size(); i++) {
        data[i] = 0;
    }
}
