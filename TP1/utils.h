#ifndef _UTILS_H_INCLUDED_
#define _UTILS_H_INCLUDED_

#include <string>
#include <iostream>

using namespace std;

enum OPT {MINUS = '-'};

//Prototipos
bool is_negative(const string &s);
size_t zerocount(const unsigned short *digits, const size_t &size);
bool is_digits_equal(const unsigned short *a, const unsigned short *b, const size_t& size);
bool validate_dict(const char& op, const char* dict);

#endif
