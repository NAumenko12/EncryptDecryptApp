#include "crypto_utils.h"

bool ravni_baiti(const vector<uint8_t>& left, const vector<uint8_t>& right) {
    bool equal = left.size() == right.size();
    for (size_t i = 0; i < left.size() && equal; i++) {
        equal = left[i] == right[i];
    }
    return equal;
}

bool test_rsa_case(const vector<uint8_t>& input) {
    int64_t p = 3557;
    int64_t q = 2579;
    int64_t n = p * q;
    int64_t phi = (p - 1) * (q - 1);
    int64_t public_key = 65537;
    int64_t private_key = alg_cherez_c(public_key, phi);
    vector<uint8_t> encrypted = rsa_zashifrovat(input, n, public_key);
    vector<uint8_t> decrypted = rsa_rasshifrovat(encrypted, n, private_key);
    bool passed = ravni_baiti(input, decrypted);
    ochistit_baiti(encrypted);
    ochistit_baiti(decrypted);
    return passed;
}

bool test_shamir_case(const vector<uint8_t>& input) {
    int64_t p = 257;
    int64_t ca = 17;
    int64_t cb = 5;
    int64_t da = alg_cherez_c(ca, p - 1);
    int64_t db = alg_cherez_c(cb, p - 1);
    vector<uint8_t> encrypted = shamir_zashifrovat(input, p, ca, cb);
    vector<uint8_t> decrypted = shamir_rasshifrovat(encrypted, p, da, db);
    bool passed = ravni_baiti(input, decrypted);
    ochistit_baiti(encrypted);
    ochistit_baiti(decrypted);
    return passed;
}

int main() {
    vector<vector<uint8_t>> test_data = {
        {0, 1, 2, 3, 4, 5},
        {'h', 'e', 'l', 'l', 'o'},
        {255, 128, 64, 32, 16, 8, 4, 2, 1}
    };
    bool all_passed = true;
    for (const vector<uint8_t>& input : test_data) {
        all_passed = test_rsa_case(input) && all_passed;
    }
    for (const vector<uint8_t>& input : test_data) {
        all_passed = test_shamir_case(input) && all_passed;
    }
    if (all_passed) {
        cout << "Все тесты пройдены.\n";
    } else {
        cout << "Есть проваленные тесты.\n";
    }
    return all_passed ? 0 : 1;
}
