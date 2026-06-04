CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -I.
TARGET = encrypt_decrypt_app
RSA_LIBRARY = librsa.so
SHAMIR_LIBRARY = libshamir.so
TEST_TARGET = test_crypto
COMMON_SOURCES = optional/bytes_to_numbers.cpp optional/numbers_to_bytes.cpp optional/numbers_to_binary.cpp optional/binary_to_numbers.cpp optional/process_numbers.cpp optional/clear_bytes.cpp optional/clear_numbers.cpp crypto_utils/mod.cpp crypto_utils/gcd.cpp crypto_utils/prime.cpp crypto_utils/euclid.cpp
SOURCES = main.cpp input_output_utils.cpp proc_console/read_choice.cpp proc_console/read_int64.cpp proc_console/read_console_data.cpp proc_console/write_console_data.cpp proc_file/read_file_data.cpp proc_file/write_file_data.cpp proc_file/read_key_file.cpp proc_file/read_file_path.cpp algorithm/algorithm.cpp $(COMMON_SOURCES) keygen/keygen.cpp keygen/rsa_key.cpp keygen/shamir_key.cpp RSA/rsa.cpp RSA/encrypt.cpp RSA/decrypt.cpp Shamir/shamir.cpp Shamir/encrypt.cpp Shamir/decrypt.cpp
TEST_SOURCES = Test/test.cpp $(COMMON_SOURCES) RSA/encrypt.cpp RSA/decrypt.cpp Shamir/encrypt.cpp Shamir/decrypt.cpp
HEADERS = crypto_utils.h crypto_utils/crypto_utils.h algorithm/algorithm.h optional/other_utils.h keygen/keygen.h RSA/rsa.h Shamir/shamir.h proc_console/proc_console.h proc_file/proc_file.h plugin_api/plugin_api.h
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET) $(RSA_LIBRARY) $(SHAMIR_LIBRARY)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp crypto_utils.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(RSA_LIBRARY): RSA/rsa_plugin.cpp RSA/encrypt.cpp RSA/decrypt.cpp $(COMMON_SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -fPIC -shared RSA/rsa_plugin.cpp RSA/encrypt.cpp RSA/decrypt.cpp $(COMMON_SOURCES) -o $(RSA_LIBRARY)

$(SHAMIR_LIBRARY): Shamir/shamir_plugin.cpp Shamir/encrypt.cpp Shamir/decrypt.cpp $(COMMON_SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -fPIC -shared Shamir/shamir_plugin.cpp Shamir/encrypt.cpp Shamir/decrypt.cpp $(COMMON_SOURCES) -o $(SHAMIR_LIBRARY)

$(TEST_TARGET): $(TEST_SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(TEST_SOURCES) -o $(TEST_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET) $(RSA_LIBRARY) $(SHAMIR_LIBRARY) $(TEST_TARGET)

clang:
	clang-format -i $(SOURCES) $(TEST_SOURCES) RSA/rsa_plugin.cpp Shamir/shamir_plugin.cpp $(HEADERS)
