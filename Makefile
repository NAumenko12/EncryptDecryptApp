CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -I.
TARGET = encrypt_decrypt_app
SOURCES = main.cpp input_output_utils.cpp proc_console/read_choice.cpp proc_console/read_int64.cpp proc_console/read_console_data.cpp proc_console/write_console_data.cpp proc_file/read_file_data.cpp proc_file/write_file_data.cpp proc_file/read_key_file.cpp proc_file/read_file_path.cpp algorithm/algorithm.cpp optional/bytes_to_numbers.cpp optional/numbers_to_bytes.cpp optional/numbers_to_binary.cpp optional/binary_to_numbers.cpp optional/process_numbers.cpp crypto_utils/mod.cpp crypto_utils/gcd.cpp crypto_utils/prime.cpp crypto_utils/euclid.cpp keygen/keygen.cpp keygen/rsa_key.cpp keygen/shamir_key.cpp RSA/rsa.cpp RSA/encrypt.cpp RSA/decrypt.cpp Shamir/shamir.cpp Shamir/encrypt.cpp Shamir/decrypt.cpp
HEADERS = crypto_utils.h crypto_utils/crypto_utils.h algorithm/algorithm.h optional/other_utils.h keygen/keygen.h RSA/rsa.h Shamir/shamir.h proc_console/proc_console.h proc_file/proc_file.h
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp crypto_utils.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

clang:
	clang-format -i $(SOURCES) $(HEADERS)
