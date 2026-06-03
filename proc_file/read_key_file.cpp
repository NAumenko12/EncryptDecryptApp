#include "crypto_utils.h"

vector<int64_t> schitat_key_iz_faila() {
    vector<uint8_t> key_bytes = schitat_dannie_iz_faila();
    vector<int64_t> key = binar_v_chisla(key_bytes);
    return key;
}
