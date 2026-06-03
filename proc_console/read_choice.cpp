#include "crypto_utils.h"

int schitat_vibor(const string& prompt, int min_value, int max_value) {
    int value {};
    bool correct = {false};
    for (int attempt = 0; attempt < 3 && !correct; attempt++) {
        cout << prompt;
        if (cin >> value) {
            correct = value >= min_value && value <= max_value;
        } else {
            correct = false;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (!correct) {
            cout << "Некорректный выбор. Попробуйте еще раз.\n";
        }
    }
    if (!correct) {
        throw runtime_error("Превышено количество попыток ввода.");
    }
    return value;
}
