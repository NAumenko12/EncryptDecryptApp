#include "crypto_utils.h"

vector<uint8_t> rsa_zashifrovat(const vector<uint8_t>& input, int64_t n, int64_t public_key) {
    vector<int64_t> encrypted = obrabotat_chisla(baiti_v_chisla(input), public_key, n);
    return chisla_v_binar(encrypted);
}
