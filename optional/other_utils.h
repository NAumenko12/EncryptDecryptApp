#ifndef OTHER_UTILS_H
#define OTHER_UTILS_H

#include <cstdint>
#include <vector>

using namespace std;

vector<int64_t> baiti_v_chisla(const vector<uint8_t>& bytes);
vector<uint8_t> chisla_v_baiti(const vector<int64_t>& numbers);
vector<uint8_t> chisla_v_binar(const vector<int64_t>& numbers);
vector<int64_t> binar_v_chisla(const vector<uint8_t>& bytes);
vector<int64_t> obrabotat_chisla(const vector<int64_t>& numbers, int64_t power, int64_t module);

#endif
