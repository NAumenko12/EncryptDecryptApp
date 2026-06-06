#include "crypto_utils.h"

vector<uint8_t> shamir_rasshifrovat(const vector<uint8_t>& input, int64_t p, int64_t da, int64_t db) {
    vector<int64_t> x3 = obrabotat_chisla(binar_v_chisla(input), da, p);
    vector<int64_t> x4 = obrabotat_chisla(x3, db, p);
    return chisla_v_baiti(x4);
}
