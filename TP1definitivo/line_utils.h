#ifndef UTILSS__H
#define UTILSS__H

#include <iostream>
#include <string>
#include "Stack.h"
#include "Token.h"
//#include "bignum.h" //MUTEADO
#include "bignum.h"
#include "functions.h" //MUTEADO

using namespace std;

Stack<Token>* shunting_yard(Stack<Token> * input);
Stack<Token>* shunting_yard2(Stack<Token>* input);
Stack<Token>* createStackTokens(Stack<string>*input);
bignum evalPostfix(Stack<Token> * postfixTK);
#endif
