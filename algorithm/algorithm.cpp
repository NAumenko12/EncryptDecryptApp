#include "crypto_utils.h"

vector<uint8_t> obrabotat_algorithm(int algorithm, bool encrypt, const vector<uint8_t>& input) {
    vector<uint8_t> result;
    if (algorithm == 1) {
        result = obrabotat_rsa(input, encrypt);
    } else {
        result = obrabotat_shamira(input, encrypt);
    }

    return result;
}

void obrabotat_algorithm_fail_potokom(int algorithm, bool encrypt, const string& input_path, const string& output_path) {
    if (algorithm == 1) {
        obrabotat_rsa_fail_potokom(encrypt, input_path, output_path);
    } else {
        obrabotat_shamira_fail_potokom(encrypt, input_path, output_path);
    }
}
