#include "crypto_utils.h"

vector<uint8_t> schitat_dannie_iz_konsoli() {
    cout << "Введите данные: ";
    string text;
    getline(cin, text);
    vector<uint8_t> bytes(text.begin(), text.end());
    return bytes;
}
