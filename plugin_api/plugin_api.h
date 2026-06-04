#ifndef PLUGIN_API_H
#define PLUGIN_API_H

#include <cstddef>
#include <cstdint>

struct ConstBuffer {
    const uint8_t* data;
    size_t size;
};

struct MutBuffer {
    uint8_t* data;
    size_t size;
};

struct AlgorithmInfo {
    const char* algorithm_name;
    size_t key_size;
};

enum OperationType {
    OPERATION_ENCRYPT = 1,
    OPERATION_DECRYPT = 2
};

enum PluginError {
    PLUGIN_OK = 0,
    PLUGIN_ERROR_INVALID_ARGUMENT = 1,
    PLUGIN_ERROR_INVALID_KEY = 2,
    PLUGIN_ERROR_BUFFER_TOO_SMALL = 3,
    PLUGIN_ERROR_CRYPTO = 4
};

#endif
