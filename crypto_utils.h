#ifndef CRYPTO_UTILS_H
#define CRYPTO_UTILS_H
#include <cstdint>
#include <fstream>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int readChoice(const string& prompt, int minValue, int maxValue);
int64_t readInt64(const string& prompt);
string readTextFromConsole();
string readTextFromFile();
string readInputText();
void writeResult(const string& result);

int64_t mod(int64_t base, int64_t power, int64_t modulo);
int64_t gcd(int64_t a, int64_t b);
bool isPrime(int64_t x);
int64_t algcherezC(int64_t base, int64_t module);

vector<int64_t> parseNumbers(const string& text);
string numbersToText(const vector<int64_t>& numbers);
vector<int64_t> textToBytes(const string& text);
string bytesToText(const vector<int64_t>& bytes);
vector<int64_t> processNumbers(const vector<int64_t>& numbers, int64_t power, int64_t module);

string runRsa(const string& input, bool encrypt, int64_t p, int64_t q, int64_t publicKey);
string processRsa(const string& input, bool encrypt);

string runShamir(const string& input, bool encrypt, int64_t p, int64_t c);
string processShamir(const string& input, bool encrypt);

#endif
