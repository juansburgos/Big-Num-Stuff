#ifndef UTILSS__H
#define UTILSS__H

#include <iostream>
#include <string>
#include "Stack.h"
#include "Token.h"
#include "bignum.h"
#include "functions.h"
#include "producto.h"

using namespace std;

Stack<Token>* shunting_yard(Stack<Token> * input);
Stack<Token>* createStackTokens(Stack<string>*input);
bignum evalPostfix(Stack<Token> * postfixTK);
#endif
