#ifndef CAESAR_H
#define CAESAR_H

#include <string>

using namespace std;

string encrypt(string text, int key);
string decrypt(string text, int key);

#endif