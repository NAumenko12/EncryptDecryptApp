#include <iostream>
using namespace std;

long long mod(long long base, long long power, long long modulo) {
    long long result = 1;
    base %= modulo;
    for (long long i = 0; i < power; i++) {
        result = (result * base) % modulo;
    }
    return result;
}

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool isPrime(long long x) {
    if (x < 2) return false;
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

long long algcherezC(long long base, long long module) {
    long long r0 = module;
    long long r1 = base;
    long long u0 = 0;
    long long u1 = 1;
    while (r1 != 0) {
        long long q = r0 / r1;
        long long nr = r0 - q * r1;
        long long nu = u0 - q * u1;
        r0 = r1;
        r1 = nr;
        u0 = u1;
        u1 = nu;
    }
    if (r0 != 1) {
        cout << "Обратного элемента не существует" << endl;
        return -1;
    }
    while (u0 < 0)
        u0 += module;
    return u0;
}

void rsa() {
    long long p = 7;
    long long q = 11;
    if (!isPrime(p) || !isPrime(q)) {
        cout << "p и q должны быть простыми числами" << endl;
        return;
    }
    long long n = p * q;
    long long phi = (p - 1) * (q - 1);
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "n = p * q = " << n << endl;
    cout << "phi(n) = " << phi << endl;
    long long Cb = 7;
    if (gcd(Cb, phi) != 1) {
        cout << "Cb не подходит, так как gcd(Cb, phi) != 1" << endl;
        return;
    }
    long long Db = algcherezC(Cb, phi);
    cout << "\nКлючи Боба:" << endl;
    cout << "Private key Cb = " << Cb << endl;
    cout << "Public key Db = " << Db << endl;
    cout << "Public key Nb = " << n << endl;
    long long m = 10;
    if (m >= n) {
        cout << "Сообщение должно быть меньше n" << endl;
        return;
    }
    cout << "\nИсходное сообщение m = " << m << endl;
    long long e = mod(m, Db, n);
    cout << "\nАлиса шифрует:" << endl;
    cout << "e = m^Db mod Nb = " << e << endl;
    long long decrypted = mod(e, Cb, n);
    cout << "\nБоб расшифровывает:" << endl;
    cout << "m' = e^Cb mod Nb = " << decrypted << endl;
}