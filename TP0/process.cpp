#include "process.h"
#include <sstream>

//Devuelve true cuando la precision es erronea
bool check_precision(const bignum &x, const bignum &y, const size_t &precision) {
	if (((x.get_size()) > precision) || ((y.get_size()) > precision)) {
		cerr << "Insufficient precision (function [check_precision])" << endl;
		return false;
	}
	return true;
}

//Verifica si el operador es valido, devuelve false en caso de ser exitoso
bool validate_opts(const char &op) {

	bool st;

	if ( (st = validate_dict(op, opt_dict)) != true) {
		return st;
	}
	return true;
}
//Chequea si el steam tuvo un error
bool check_stream(istream* is, ostream* os) {

	if (os->bad()) {
		cerr << "cannot write to output stream."
			<< endl;
			return false;
	}
	if (is->bad()) {
		cerr << "cannot read from input stream."
			<< endl;
			return false;
	}
	if (!is->eof()) {
		cerr << "cannot find EOF on input stream."
			<< endl;
			return false;
	}
	return true;
}
//Devuelve true cuando se procesa la entrada satisfactoriamente.
bool process_input(istream *is, ostream *os, size_t precision){
	bignum x, y;
	char op,c;
	bool st;


	while (!is->eof()){

		*is >> x >> op >> y;

		if ((st = check_precision(x, y, precision)) == false){
			return st;
		}
		if ((st = validate_opts(op)) == false){
			return st;
		}
		if (op == opt_dict[SUM])
			*os << x + y << endl;

		if (op == opt_dict[MIN])
			*os << x - y << endl;

		if (op == opt_dict[PROD])
			*os << x * y << endl;

		*is >> c;

		if ((is->rdstate() & ios::eofbit ) != 0)
			break;
		else
			is->putback(c);

	}

	if ((st = check_stream(is, os)) == false){
		return st;
	}
	return true;
}
