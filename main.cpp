#include "crypto_utils.h"

int main() {
    try {
        cout << "EncryptDecryptApp\n";
        cout << "1. Зашифровать\n";
        cout << "2. Расшифровать\n";
        cout << "3. Сгенерировать ключ\n";
        int action = schitat_vibor("Ваш выбор: ", 1, 3);
        bool encrypt = action == 1;
        cout << "\nАлгоритм:\n";
        cout << "1. RSA\n";
        cout << "2. Шамир\n";
        int algorithm = schitat_vibor("Ваш выбор: ", 1, 2);
        vector<uint8_t> result;
        
        if (action == 3) {
            result = sgenerirovat_key(algorithm);
            zapisat_resultat(result);
        } else {
            string input_path = schitat_put_k_failu("Введите путь к входному файлу: ");
            string output_path = schitat_put_k_failu("Введите путь к выходному файлу: ");
            obrabotat_algorithm_fail_potokom(algorithm, encrypt, input_path, output_path);
        }
    } catch (const exception& error) {
        cout << "Ошибка: " << error.what() << endl;
        return 1;
    }
    return 0;
}
