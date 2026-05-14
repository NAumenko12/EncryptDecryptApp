#include "crypto_utils.h"

vector<int64_t> parseNumbers(const string& text) {
    vector<int64_t> numbers;
    istringstream stream(text);
    int64_t number = 0;
    while (stream >> number) {
        numbers.push_back(number);
    }
    return numbers;
}

string numbersToText(const vector<int64_t>& numbers) {
    ostringstream stream;
    for (size_t i = 0; i < numbers.size(); ++i) {
        if (i > 0) {
            stream << ' ';
        }
        stream << numbers[i];
    }
    return stream.str();
}

vector<int64_t> textToBytes(const string& text) {
    vector<int64_t> bytes;
    bytes.reserve(text.size());
    for (unsigned char symbol : text) {
        bytes.push_back(static_cast<int64_t>(symbol));
    }
    return bytes;
}

string bytesToText(const vector<int64_t>& bytes) {
    string text;
    text.reserve(bytes.size());
    for (int64_t byte : bytes) {
        try {
            if (byte < 0 || byte > 255) {
                throw out_of_range("значение не помещается в байт");
            }
            text.push_back(static_cast<char>(byte));
        } catch (const out_of_range& error) {
            cout << "Предупреждение: значение " << byte << " " << error.what() << " и будет пропущено.\n";
        }
    }
    return text;
}

vector<int64_t> processNumbers(const vector<int64_t>& numbers, int64_t power, int64_t module) {
    vector<int64_t> result;
    result.reserve(numbers.size());
    for (int64_t number : numbers) {
        result.push_back(mod(number, power, module));
    }
    return result;
}
