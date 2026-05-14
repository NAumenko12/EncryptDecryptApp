#include "crypto_utils.h"

/*
void shamira() {
    int64_t m{};
    int64_t p{};
    int64_t Ca{};
    int64_t Cb{};
    cout << "Введите сообщение m: ";
    cin >> m;
    cout << "Введите простое число p: ";
    cin >> p;
    cout << "Введите ключ Ca: ";
    cin >> Ca;
    cout << "Введите ключ Cb: ";
    cin >> Cb;
    if (!isPrime(p)) {
        cout << "p должно быть простым числом" << endl;
        return;
    }
    int64_t Da = algcherezC(Ca, p - 1);
    int64_t Db = algcherezC(Cb, p - 1);
    if (Da == -1 || Db == -1) {
        return;
    }
    cout << "Da = " << Da << endl;
    cout << "Db = " << Db << endl;
    int64_t X1 = mod(m, Ca, p);
    cout << "X1 = " << X1 << endl;
    int64_t X2 = mod(X1, Cb, p);
    cout << "X2 = " << X2 << endl;
    int64_t X3 = mod(X2, Da, p);
    cout << "X3 = " << X3 << endl;
    int64_t X4 = mod(X3, Db, p);
    cout << "X4 = " << X4 << endl;
    cout << "Исходное сообщение = " << X4 << endl;
}

*/

string processShamir(const string& input, bool encrypt) {
    cout << "\nПараметры Шамира:\n";
    int64_t p = readInt64("Введите простое число p: ");
    int64_t c = readInt64("Введите ключ c: ");

    return runShamir(input, encrypt, p, c);
}

string runShamir(const string& input, bool encrypt, int64_t p, int64_t c) {
    if (!isPrime(p)) {
        return "Ошибка: p должно быть простым числом.";
    }
    if (p <= 255) {
        return "Ошибка: p должно быть больше 255, чтобы можно было шифровать текст.";
    }
    int64_t d = algcherezC(c, p - 1);
    if (d == -1) {
        return "Ошибка: не удалось подготовить ключи Шамира.";
    }
    if (encrypt) {
        return numbersToText(processNumbers(textToBytes(input), c, p));
    }

    return bytesToText(processNumbers(parseNumbers(input), d, p));
}