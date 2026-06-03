#include "crypto_utils.h"

void zapisat_dannie_v_fail(const vector<uint8_t>& result) {
    bool correct = false;
    for (int attempt = 0; attempt < 3 && !correct; attempt++) {
        cout << "Введите путь к файлу для записи: ";
        string path;
        getline(cin, path);
        ofstream file(path, ios::binary);
        correct = file.good();
        if (correct) {
            file.write(reinterpret_cast<const char*>(result.data()), static_cast<streamsize>(result.size()));
            cout << "Результат записан в файл.\n";
        } else {
            cout << "Не удалось записать файл. Попробуйте еще раз.\n";
        }
    }
    if (!correct) {
        throw runtime_error("Не удалось записать файл.");
    }
}
