#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <cstdint>
#include <vector>

using namespace std;

vector<uint8_t> obrabotat_algorithm(int algorithm, bool encrypt, const vector<uint8_t>& input);
void obrabotat_algorithm_fail_potokom(int algorithm, bool encrypt, const string& input_path, const string& output_path);

#endif
