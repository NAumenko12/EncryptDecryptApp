#include "crypto_utils.h"
/*
void rsa() {
    int64_t p{};
    int64_t q{};
    int64_t Cb{};
    int64_t m{};
    cout << "Введите простое число p: ";
    cin >> p;
    cout << "Введите простое число q: ";
    cin >> q;
    if (!isPrime(p) || !isPrime(q)) {
        cout << "p и q должны быть простыми числами" << endl;
        return;
    }
    int64_t n = p * q;
    int64_t phi = (p - 1) * (q - 1);
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "n = p * q = " << n << endl;
    cout << "phi(n) = " << phi << endl;
    cout << "Введите закрытый ключ Cb: ";
    cin >> Cb;
    if (gcd(Cb, phi) != 1) {
        cout << "Cb не подходит, так как gcd(Cb, phi) != 1" << endl;
        return;
    }
    int64_t Db = algcherezC(Cb, phi);
    cout << "\nКлючи Боба:" << endl;
    cout << "Private key Cb = " << Cb << endl;
    cout << "Public key Db = " << Db << endl;
    cout << "Public key Nb = " << n << endl;
    cout << "Введите сообщение m: ";
    cin >> m;
    if (m >= n) {
        cout << "Сообщение должно быть меньше n" << endl;
        return;
    }
    cout << "\nИсходное сообщение m = " << m << endl;
    int64_t e = mod(m, Db, n);
    cout << "\nАлиса шифрует:" << endl;
    cout << "e = m^Db mod Nb = " << e << endl;
    int64_t decrypted = mod(e, Cb, n);
    cout << "\nБоб расшифровывает:" << endl;
    cout << "m' = e^Cb mod Nb = " << decrypted << endl;
}
*/

string runRsa(const string& input, bool encrypt, int64_t p, int64_t q, int64_t publicKey) {
    if (!isPrime(p) || !isPrime(q)) {
        return "Ошибка: p и q должны быть простыми числами.";
    }
    int64_t n = p * q;
    int64_t phi = (p - 1) * (q - 1);
    int64_t privateKey = algcherezC(publicKey, phi);
    if (privateKey == -1 || gcd(publicKey, phi) != 1) {
        return "Ошибка: не удалось подготовить ключи RSA.";
    }
    if (n <= 255) {
        return "Ошибка: n должно быть больше 255, чтобы можно было шифровать текст.";
    }
    if (encrypt) {
        return numbersToText(processNumbers(textToBytes(input), publicKey, n));
    }
    return bytesToText(processNumbers(parseNumbers(input), privateKey, n));
}

string processRsa(const string& input, bool encrypt) {
    cout << "\nПараметры RSA:\n";
    int64_t p = readInt64("Введите простое число p: ");
    int64_t q = readInt64("Введите простое число q: ");
    int64_t publicKey = readInt64("Введите открытую степень e: ");
    return runRsa(input, encrypt, p, q, publicKey);
}
