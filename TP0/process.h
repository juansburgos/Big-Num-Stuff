#ifndef _PROCESS_H_INCLUDED_
#define _PROCESS_H_INCLUDED_
#include "utils.h"
#include <iostream>
#include "Bignum.h"

//Diccionario de operadores
enum OPERATORS { SUM = 0, MIN, PROD};
const char opt_dict[] = {'+', '-', '*'};

enum class ERRORS_PROCESS { PRECISION, OPERATOR, WOUTSTREAM, RINSTREAM, EOFINSTREAM};

bool check_precision(const Bignum &x, const Bignum &y, const size_t &precision);
bool validate_opts(const char &op);
bool check_stream(istream* is, ostream* os);
bool process_input(istream *is, ostream *os, size_t precision);

#endif
