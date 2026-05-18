#include "crypto_utils.h"

int schitat_vibor(const string& prompt, int min_value, int max_value){
    int value {};
    bool correct = {false};
    for (int attempt = 0; attempt < 3 && !correct; attempt++){
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

int64_t schitat_int64(const string& prompt) {
    int64_t value {};
    bool correct = {false};
    for (int attempt = 0; attempt < 3 && !correct; attempt++){
        cout << prompt;
        if (cin >> value){
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

vector<uint8_t> schitat_dannie_iz_konsoli(){
    cout << "Введите данные: ";
    string text;
    getline(cin, text);
    vector<uint8_t> bytes(text.begin(), text.end());
    return bytes;
}

vector<uint8_t> schitat_dannie_iz_faila(){
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

vector<uint8_t> schitat_vhodnie_dannie(){
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

void zapisat_resultat(const vector<uint8_t>& result){
    cout << "\nКуда вывести результат:\n";
    cout << "1. Консоль\n";
    cout << "2. Файл\n";
    int target = schitat_vibor("Ваш выбор: ", 1, 2);
    if (target == 1) {
        cout.write(reinterpret_cast<const char*>(result.data()), static_cast<streamsize>(result.size()));
        cout << '\n';
    } else {
        bool correct = false;
        for (int attempt = 0; attempt < 3 && !correct; attempt++){
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
}
