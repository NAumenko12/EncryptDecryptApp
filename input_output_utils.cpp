#include "crypto_utils.h"

vector<uint8_t> schitat_vhodnie_dannie() {
    vector<uint8_t> bytes;
    cout << "\nОткуда взять данные:\n";
    cout << "1. Консоль\n";
    cout << "2. Файл\n";
    int source = schitat_vibor("Ваш выбор: ", 1, 2);
    if (source == 1) {
        bytes = schitat_dannie_iz_konsoli();
    } else {
        bytes = schitat_dannie_iz_faila();
    }
    return bytes;
}

void zapisat_resultat(const vector<uint8_t>& result) {
    cout << "\nКуда вывести результат:\n";
    cout << "1. Консоль\n";
    cout << "2. Файл\n";
    int target = schitat_vibor("Ваш выбор: ", 1, 2);
    if (target == 1) {
        zapisat_dannie_v_konsol(result);
    } else {
        zapisat_dannie_v_fail(result);
    }
}
