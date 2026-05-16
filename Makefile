CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror
TARGET = encrypt_decrypt_app
SOURCES = main.cpp crypto_utils.cpp input_output_utils.cpp other_utils.cpp rsa.cpp shamir.cpp
HEADERS = crypto_utils.h
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
