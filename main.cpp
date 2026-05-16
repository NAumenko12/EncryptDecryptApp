#include "crypto_utils.h"

int main() {
    try {
        cout << "EncryptDecryptApp\n";
        cout << "1. Зашифровать\n";
        cout << "2. Расшифровать\n";
        int action = schitat_vibor("Ваш выбор: ", 1, 2);
        bool encrypt = action == 1;
        cout << "\nАлгоритм:\n";
        cout << "1. RSA\n";
        cout << "2. Шамир\n";
        int algorithm = schitat_vibor("Ваш выбор: ", 1, 2);
        vector<uint8_t> input = schitat_vhodnie_dannie();
        vector<uint8_t> result;
        if (algorithm == 1) {
            result = obrabotat_rsa(input, encrypt);
        } else {
            result = obrabotat_shamira(input, encrypt);
        }
        zapisat_resultat(result);
    } catch (const exception& error) {
        cout << "Ошибка: " << error.what() << endl;
        return 1;
    }
    return 0;
}
