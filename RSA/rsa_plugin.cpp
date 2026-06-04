#include "crypto_utils.h"
#include "plugin_api/plugin_api.h"

extern "C" const AlgorithmInfo* get_algorithm_info() {
    static AlgorithmInfo info = {"rsa", 6 * sizeof(int64_t)};
    return &info;
}

extern "C" size_t get_output_size(size_t input_size, int operation_type) {
    size_t output_size = 0;
    if (operation_type == OPERATION_ENCRYPT) {
        output_size = input_size * sizeof(int64_t);
    } else if (operation_type == OPERATION_DECRYPT) {
        output_size = input_size / sizeof(int64_t);
    }
    return output_size;
}

extern "C" int encrypt(ConstBuffer key_buffer, ConstBuffer input, MutBuffer* output) {
    int error = PLUGIN_OK;
    try {
        if (key_buffer.data == nullptr || input.data == nullptr || output == nullptr || output->data == nullptr) {
            error = PLUGIN_ERROR_INVALID_ARGUMENT;
        } else {
            vector<uint8_t> key_bytes(key_buffer.data, key_buffer.data + key_buffer.size);
            vector<int64_t> key = binar_v_chisla(key_bytes);
            if (key.size() != 6 || key[0] != 1) {
                error = PLUGIN_ERROR_INVALID_KEY;
            } else {
                size_t needed_size = get_output_size(input.size, OPERATION_ENCRYPT);
                if (output->size < needed_size) {
                    error = PLUGIN_ERROR_BUFFER_TOO_SMALL;
                } else {
                    vector<uint8_t> input_bytes(input.data, input.data + input.size);
                    vector<uint8_t> result = rsa_zashifrovat(input_bytes, key[3], key[4]);
                    copy(result.begin(), result.end(), output->data);
                    output->size = result.size();
                    ochistit_baiti(input_bytes);
                    ochistit_baiti(result);
                }
            }
            ochistit_baiti(key_bytes);
            ochistit_chisla(key);
        }
    } catch (...) {
        error = PLUGIN_ERROR_CRYPTO;
    }
    return error;
}

extern "C" int decrypt(ConstBuffer key_buffer, ConstBuffer input, MutBuffer* output) {
    int error = PLUGIN_OK;
    try {
        if (key_buffer.data == nullptr || input.data == nullptr || output == nullptr || output->data == nullptr) {
            error = PLUGIN_ERROR_INVALID_ARGUMENT;
        } else {
            vector<uint8_t> key_bytes(key_buffer.data, key_buffer.data + key_buffer.size);
            vector<int64_t> key = binar_v_chisla(key_bytes);
            if (key.size() != 6 || key[0] != 1) {
                error = PLUGIN_ERROR_INVALID_KEY;
            } else {
                size_t needed_size = get_output_size(input.size, OPERATION_DECRYPT);
                if (output->size < needed_size || input.size % sizeof(int64_t) != 0) {
                    error = PLUGIN_ERROR_BUFFER_TOO_SMALL;
                } else {
                    vector<uint8_t> input_bytes(input.data, input.data + input.size);
                    vector<uint8_t> result = rsa_rasshifrovat(input_bytes, key[3], key[5]);
                    copy(result.begin(), result.end(), output->data);
                    output->size = result.size();
                    ochistit_baiti(input_bytes);
                    ochistit_baiti(result);
                }
            }
            ochistit_baiti(key_bytes);
            ochistit_chisla(key);
        }
    } catch (...) {
        error = PLUGIN_ERROR_CRYPTO;
    }
    return error;
}
