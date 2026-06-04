#include "crypto_utils.h"
#include "plugin_api/plugin_api.h"

#include <dlfcn.h>

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
    string library_path = algorithm == 1 ? "./librsa.so" : "./libshamir.so";
    string key_name = algorithm == 1 ? "\nКлюч RSA:\n" : "\nКлюч Шамира:\n";
    cout << key_name;
    vector<uint8_t> key = schitat_dannie_iz_faila();

    void* library = dlopen(library_path.c_str(), RTLD_NOW);
    if (library == nullptr) {
        ochistit_baiti(key);
        throw runtime_error("Не удалось загрузить библиотеку алгоритма.");
    }

    using CryptFunction = int (*)(ConstBuffer, ConstBuffer, MutBuffer*);
    using SizeFunction = size_t (*)(size_t, int);

    CryptFunction crypt_function = nullptr;
    if (encrypt) {
        crypt_function = reinterpret_cast<CryptFunction>(dlsym(library, "encrypt"));
    } else {
        crypt_function = reinterpret_cast<CryptFunction>(dlsym(library, "decrypt"));
    }
    SizeFunction get_output_size = reinterpret_cast<SizeFunction>(dlsym(library, "get_output_size"));

    if (crypt_function == nullptr || get_output_size == nullptr) {
        dlclose(library);
        ochistit_baiti(key);
        throw runtime_error("Не удалось получить функции из библиотеки алгоритма.");
    }

    ifstream input_file(input_path, ios::binary);
    ofstream output_file(output_path, ios::binary);
    if (!input_file || !output_file) {
        dlclose(library);
        ochistit_baiti(key);
        throw runtime_error("Не удалось открыть входной или выходной файл.");
    }

    size_t chunk_size = encrypt ? 4096 : 4096 * sizeof(int64_t);
    vector<char> buffer(chunk_size);

    for (input_file.read(buffer.data(), buffer.size()); input_file.gcount() > 0; input_file.read(buffer.data(), buffer.size())) {
        streamsize read_count = input_file.gcount();
        if (!encrypt && read_count % sizeof(int64_t) != 0) {
            dlclose(library);
            ochistit_baiti(key);
            throw runtime_error("Размер шифротекста некорректен.");
        }

        vector<uint8_t> input_chunk(buffer.begin(), buffer.begin() + read_count);
        size_t output_size = get_output_size(input_chunk.size(), encrypt ? OPERATION_ENCRYPT : OPERATION_DECRYPT);
        vector<uint8_t> output_chunk(output_size);

        ConstBuffer key_buffer = {key.data(), key.size()};
        ConstBuffer input_buffer = {input_chunk.data(), input_chunk.size()};
        MutBuffer output_buffer = {output_chunk.data(), output_chunk.size()};

        int error = crypt_function(key_buffer, input_buffer, &output_buffer);
        if (error != PLUGIN_OK) {
            dlclose(library);
            ochistit_baiti(key);
            ochistit_baiti(input_chunk);
            ochistit_baiti(output_chunk);
            throw runtime_error("Библиотека вернула ошибку обработки.");
        }

        output_file.write(reinterpret_cast<const char*>(output_chunk.data()), static_cast<streamsize>(output_buffer.size));
        ochistit_baiti(input_chunk);
        ochistit_baiti(output_chunk);
    }

    dlclose(library);
    ochistit_baiti(key);
    cout << "Файл обработан через библиотеку.\n";
}
