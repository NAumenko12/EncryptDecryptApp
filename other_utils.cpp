#include "crypto_utils.h"

vector<int64_t> baiti_v_chisla(const vector<uint8_t>& bytes){
    vector<int64_t> numbers;
    numbers.reserve(bytes.size());
    for (uint8_t byte : bytes) {
        numbers.push_back(static_cast<int64_t>(byte));
    }
    return numbers;
}

vector<uint8_t> chisla_v_baiti(const vector<int64_t>& numbers){
    vector<uint8_t> bytes;
    bytes.reserve(numbers.size());
    for (int64_t number : numbers){
        try{
            if (number < 0 || number > 255){
                throw out_of_range("значение не помещается в байт");
            }
            uint8_t byte = number;
            bytes.push_back(byte);
        } catch (const out_of_range& error){
            cout << "Предупреждение: значение " << number << " " << error.what() << " и будет пропущено.\n";
        }
    }
    return bytes;
}

vector<uint8_t> chisla_v_binar(const vector<int64_t>& numbers){
    vector<uint8_t> bytes;
    bytes.reserve(numbers.size() * sizeof(int64_t));
    vector<int> shifts = {0, 8, 16, 24, 32, 40, 48, 56};
    for (int64_t number : numbers) {
        uint64_t value = number;
        for (int shift : shifts){
            uint8_t byte = (value >> shift) & 255;
            bytes.push_back(byte);
        }
    }
    return bytes;
}

vector<int64_t> binar_v_chisla(const vector<uint8_t>& bytes){
    vector<int64_t> numbers;
    if (bytes.size() % sizeof(int64_t) != 0){
        throw runtime_error("Размер шифротекста некорректен.");
    }
    uint64_t value {};
    int shift {};
    for (uint8_t byte : bytes){
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

vector<int64_t> obrabotat_chisla(const vector<int64_t>& numbers, int64_t power, int64_t module){
    vector<int64_t> result;
    result.reserve(numbers.size());
    for (int64_t number : numbers) {
        result.push_back(mod(number, power, module));
    }
    return result;
}
