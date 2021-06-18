#ifndef _PROCESS_H_INCLUDED_
#define _PROCESS_H_INCLUDED_
#include "utils.h"
#include <iostream>
#include "bignum.h"
#include <sstream>
#include "stack.h"
#include "functions.h"
#include "Token.h"
#include "stringUtils.h"
#include "line_utils.h"
#include "producto.h"

//Diccionario de operadores
enum OPERATORS { SUM = 0, MIN, PROD};
const char opt_dict[] = {'+', '-', '*','\0'};

enum class ERRORS_PROCESS { PRECISION, OPERATOR, WOUTSTREAM, RINSTREAM, EOFINSTREAM};

Stack<Token>* process_line(string const& arg);

bool check_precision(const bignum &x, const bignum &y, const size_t &precision);
bool validate_opts(const char &op);
bool process_input(istream *is, ostream *os);
#endif
