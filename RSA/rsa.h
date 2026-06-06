#ifndef RSA_H
#define RSA_H

#include <cstdint>
#include <vector>

using namespace std;

vector<uint8_t> rsa_zashifrovat(const vector<uint8_t>& input, int64_t n, int64_t public_key);
vector<uint8_t> rsa_rasshifrovat(const vector<uint8_t>& input, int64_t n, int64_t private_key);
vector<uint8_t> zapustit_rsa(const vector<uint8_t>& input, bool encrypt, int64_t p, int64_t q, int64_t public_key);
vector<uint8_t> obrabotat_rsa(const vector<uint8_t>& input, bool encrypt);
void obrabotat_rsa_fail_potokom(bool encrypt, const string& input_path, const string& output_path);

#endif
