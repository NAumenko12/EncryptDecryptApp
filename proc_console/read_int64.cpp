#include "crypto_utils.h"

int64_t schitat_int64(const string& prompt) {
    int64_t value {};
    bool correct = {false};
    for (int attempt = 0; attempt < 3 && !correct; attempt++) {
        cout << prompt;
        if (cin >> value) {
            correct = true;
        } else {
            correct = false;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (!correct) {
            cout << "Некорректное число. Попробуйте еще раз.\n";
        }
    }
    if (!correct) {
        throw runtime_error("Превышено количество попыток ввода числа.");
    }
    return value;
}
