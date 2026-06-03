#include "crypto_utils.h"

void zapisat_dannie_v_konsol(const vector<uint8_t>& result) {
    cout.write(reinterpret_cast<const char*>(result.data()), static_cast<streamsize>(result.size()));
    cout << '\n';
}
