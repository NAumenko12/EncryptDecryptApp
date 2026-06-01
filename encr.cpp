#include <iostream>
#include <string>

using namespace std;

string encrypt(string text, int key){
    for(char &c : text){
        if(isalpha(c)){
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + key ) % 26 + base;
        }
    }

    return text;


}