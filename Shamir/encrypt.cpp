#include "crypto_utils.h"

vector<uint8_t> shamir_zashifrovat(const vector<uint8_t>& input, int64_t p, int64_t ca, int64_t cb) {
    vector<int64_t> x1 = obrabotat_chisla(baiti_v_chisla(input), ca, p);
    vector<int64_t> x2 = obrabotat_chisla(x1, cb, p);
    return chisla_v_binar(x2);
}
