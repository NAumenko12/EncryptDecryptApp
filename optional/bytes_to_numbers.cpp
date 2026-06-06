#include "crypto_utils.h"

vector<int64_t> baiti_v_chisla(const vector<uint8_t>& bytes) {
    vector<int64_t> numbers;
    numbers.reserve(bytes.size());
    for (uint8_t byte : bytes) {
        numbers.push_back(static_cast<int64_t>(byte));
    }
    return numbers;
}
