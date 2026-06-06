#ifndef PROC_CONSOLE_H
#define PROC_CONSOLE_H

#include <cstdint>
#include <string>
#include <vector>

using namespace std;

int schitat_vibor(const string& prompt, int min_value, int max_value);
int64_t schitat_int64(const string& prompt);
vector<uint8_t> schitat_dannie_iz_konsoli();
void zapisat_dannie_v_konsol(const vector<uint8_t>& result);

#endif
