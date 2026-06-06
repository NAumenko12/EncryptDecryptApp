#include "crypto_utils.h"

vector<uint8_t> rsa_rasshifrovat(const vector<uint8_t>& input, int64_t n, int64_t private_key) {
    vector<int64_t> decrypted = obrabotat_chisla(binar_v_chisla(input), private_key, n);
    return chisla_v_baiti(decrypted);
}
