#ifndef _UTILS_H_INCLUDED_
#define _UTILS_H_INCLUDED_

#include <string>
#include <iostream>
//#include "Stack.h"
//#include "Token.h"
//#include "bignum.h" //MUTEADO
//#include "bignum.h"
//#include "functions.h" //MUTEADO

using namespace std;

enum OPT {MINUS = '-'};

//Prototipos
bool is_negative(const string &s);
size_t zerocount(const unsigned short *digits, const size_t &size);
bool is_digits_equal(const unsigned short *a, const unsigned short *b, const size_t& size);
bool validate_dict(const char& op, const char* dict);

//Implementado
//Stack<Token>* shunting_yard(Stack<Token>* input);
//Stack<Token>* createStackTokens(Stack<string>* input);
//bignum evalPostfix(Stack<Token>* postfixTK, bignum var);
#endif
