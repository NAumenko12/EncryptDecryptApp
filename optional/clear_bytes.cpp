#include "crypto_utils.h"

void ochistit_baiti(vector<uint8_t>& bytes) {
    volatile uint8_t* data = bytes.data();
    for (size_t i = 0; i < bytes.size(); i++) {
        data[i] = 0;
    }
}
