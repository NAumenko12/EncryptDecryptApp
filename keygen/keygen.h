#ifndef KEYGEN_H
#define KEYGEN_H

#include <cstdint>
#include <vector>

using namespace std;

int64_t random_chislo(int64_t min_value, int64_t max_value);
int64_t random_prime(int64_t min_value, int64_t max_value);
int64_t random_coprime(int64_t module);
vector<uint8_t> sgenerirovat_rsa_key();
vector<uint8_t> sgenerirovat_shamir_key();
vector<uint8_t> sgenerirovat_key(int algorithm);

#endif
