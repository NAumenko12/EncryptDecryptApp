#include "crypto_utils.h"

vector<int64_t> binar_v_chisla(const vector<uint8_t>& bytes) {
    vector<int64_t> numbers;
    if (bytes.size() % sizeof(int64_t) != 0) {
        throw runtime_error("Размер шифротекста некорректен.");
    }
    uint64_t value {};
    int shift {};
    for (uint8_t byte : bytes) {
        uint64_t part = byte;
        value |= part << shift;
        shift += 8;
        if (shift == 64) {
            int64_t number = value;
            numbers.push_back(number);
            value = 0;
            shift = 0;
        }
    }
    return numbers;
}
