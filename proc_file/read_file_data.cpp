#include "crypto_utils.h"

vector<uint8_t> schitat_dannie_iz_faila() {
    vector<uint8_t> bytes;
    bool correct = false;
    for (int attempt = 0; attempt < 3 && !correct; attempt++) {
        cout << "Введите путь к файлу: ";
        string path;
        getline(cin, path);
        ifstream file(path, ios::binary);
        correct = file.good();
        if (correct) {
            bytes.assign(istreambuf_iterator<char>(file), istreambuf_iterator<char>());
        } else {
            cout << "Не удалось открыть файл. Попробуйте еще раз.\n";
        }
    }
    if (!correct) {
        throw runtime_error("Не удалось открыть файл.");
    }
    return bytes;
}
