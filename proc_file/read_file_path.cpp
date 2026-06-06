#include "crypto_utils.h"

string schitat_put_k_failu(const string& prompt) {
    cout << prompt;
    string path;
    getline(cin, path);
    return path;
}
