#ifndef CRYPTO_UTILS_H
#define CRYPTO_UTILS_H

#include <cstdint>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

int schitat_vibor(const string& prompt, int min_value, int max_value);
int64_t schitat_int64(const string& prompt);
vector<uint8_t> schitat_dannie_iz_konsoli();
vector<uint8_t> schitat_dannie_iz_faila();
vector<uint8_t> schitat_vhodnie_dannie();
void zapisat_resultat(const vector<uint8_t>& result);
int64_t mod(int64_t base, int64_t power, int64_t modulo);
int64_t gcd(int64_t a, int64_t b);
bool is_prime(int64_t x);
int64_t alg_cherez_c(int64_t base, int64_t module);
vector<int64_t> baiti_v_chisla(const vector<uint8_t>& bytes);
vector<uint8_t> chisla_v_baiti(const vector<int64_t>& numbers);
vector<uint8_t> chisla_v_binar(const vector<int64_t>& numbers);
vector<int64_t> binar_v_chisla(const vector<uint8_t>& bytes);
vector<int64_t> obrabotat_chisla(const vector<int64_t>& numbers, int64_t power, int64_t module);
vector<uint8_t> zapustit_rsa(const vector<uint8_t>& input, bool encrypt, int64_t p, int64_t q, int64_t public_key);
vector<uint8_t> obrabotat_rsa(const vector<uint8_t>& input, bool encrypt);
vector<uint8_t> zapustit_shamira(const vector<uint8_t>& input, bool encrypt, int64_t p, int64_t ca, int64_t cb);
vector<uint8_t> obrabotat_shamira(const vector<uint8_t>& input, bool encrypt);

#endif
