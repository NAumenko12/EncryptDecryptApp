#ifndef CRYPTO_UTILS_H
#define CRYPTO_UTILS_H

#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

#include "crypto_utils/crypto_utils.h"
#include "optional/other_utils.h"
#include "algorithm/algorithm.h"
#include "RSA/rsa.h"
#include "Shamir/shamir.h"
#include "keygen/keygen.h"
#include "proc_console/proc_console.h"
#include "proc_file/proc_file.h"

vector<uint8_t> schitat_vhodnie_dannie();
void zapisat_resultat(const vector<uint8_t>& result);

#endif
