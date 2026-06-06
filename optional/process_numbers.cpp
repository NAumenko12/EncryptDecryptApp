#include "crypto_utils.h"

vector<int64_t> obrabotat_chisla(const vector<int64_t>& numbers, int64_t power, int64_t module) {
    vector<int64_t> result;
    result.reserve(numbers.size());
    for (int64_t number : numbers) {
        result.push_back(mod(number, power, module));
    }
    return result;
}
