#include "crypto_utils.h"

vector<uint8_t> chisla_v_baiti(const vector<int64_t>& numbers) {
    vector<uint8_t> bytes;
    bytes.reserve(numbers.size());
    for (int64_t number : numbers) {
        try {
            if (number < 0 || number > 255) {
                throw out_of_range("значение не помещается в байт");
            }
            uint8_t byte = number;
            bytes.push_back(byte);
        } catch (const out_of_range& error) {
            cout << "Предупреждение: значение " << number << " " << error.what() << " и будет пропущено.\n";
        }
    }
    return bytes;
}
