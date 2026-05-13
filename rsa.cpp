#include <iostream>
using namespace std;

int algcherezC(int base, int module) {
    int r0 = module;
    int r1 = base;
    int u0 = 0;
    int u1 = 1;
    while (r1 != 0) {
        int q = r0 / r1;
        int nr = r0 - q * r1;
        int nu = u0 - q * u1;
        r0 = r1;
        r1 = nr;
        u0 = u1;
        u1 = nu;
    }
    if (u0 < 0){
        u0 += module;
    }
    return u0;
}

int mod(int base, int power, int modulo) {
    base %= modulo;
    power %= modulo - 1;
    int result = 1;
    for (int i = 0; i < power; ++i) {
        result *= base;
        result %= modulo;
    }
    return result;
}

void shamira() {
    int m = 10;
    int p = 23;
    int Ca = 7;
    int Cb = 5;
    int Da = algcherezC(Ca, p - 1);
    int Db = algcherezC(Cb, p - 1);
    cout << "Da = " << Da << endl;
    cout << "Db = " << Db << endl;
    int X1 = mod(m, Ca, p);
    cout << "X1 = " << X1 << endl;
    int X2 = mod(X1, Cb, p);
    cout << "X2 = " << X2 << endl;
    int X3 = mod(X2, Da, p);
    cout << "X3 = " << X3 << endl;
    int X4 = mod(X3, Db, p);
    cout << "X4 = " << X4 << endl;
    cout << "Исходное сообщение = " << X4 << endl;
}