#ifndef SHAMIR_H
#define SHAMIR_H

#include <cstdint>
#include <vector>

using namespace std;

vector<uint8_t> shamir_zashifrovat(const vector<uint8_t>& input, int64_t p, int64_t ca, int64_t cb);
vector<uint8_t> shamir_rasshifrovat(const vector<uint8_t>& input, int64_t p, int64_t da, int64_t db);
vector<uint8_t> zapustit_shamira(const vector<uint8_t>& input, bool encrypt, int64_t p, int64_t ca, int64_t cb);
vector<uint8_t> obrabotat_shamira(const vector<uint8_t>& input, bool encrypt);
void obrabotat_shamira_fail_potokom(bool encrypt, const string& input_path, const string& output_path);

#endif
