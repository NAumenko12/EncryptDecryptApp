#ifndef PROC_FILE_H
#define PROC_FILE_H

#include <cstdint>
#include <string>
#include <vector>

using namespace std;

vector<uint8_t> schitat_dannie_iz_faila();
void zapisat_dannie_v_fail(const vector<uint8_t>& result);
vector<int64_t> schitat_key_iz_faila();
string schitat_put_k_failu(const string& prompt);

#endif
