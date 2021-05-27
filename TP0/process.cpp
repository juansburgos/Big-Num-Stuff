#include "process.h"
#include <sstream>
//#include "utils.h"

//Devuelve true cuando la precision es erronea
void check_precision(const Bignum &x, const Bignum &y, const size_t &precision) {
	if (((x.get_size()) > precision) || ((y.get_size()) > precision)) {
		cerr << "Insuficient precision (function [check_precision])" << endl;
		exit(1);
	}
	return;
}

//Verifica si el operador es valido, devuelve false en caso de ser exitoso
void validate_opts(const char &op) {
	if (validate_dict(op, opt_dict)) {
		return;
	}

	cerr << "Incorrect operator (function [validate_opts])" << endl;
	exit(1);
}

//Hace la cuenta matematica
Bignum do_math(const Bignum& x, const Bignum& y, const char& op) {
	if (op == opt_dict[SUM])
		return x + y;

	if (op == opt_dict[MIN])
		return x - y;

	if (op == opt_dict[PROD])
		return x * y;

	cerr << "Incorrect operator (function [do_math])" << endl;
	exit(1);
}

//Chequea si el steam tuvo un error
void check_stream(istream* is, ostream* os) {
	if (os->bad()) {
		cerr << "cannot write to output stream."
			<< endl;
	}
	else if (is->bad()) {
		cerr << "cannot read from input stream."
			<< endl;
	}

	else if (!is->eof()) {
		cerr << "cannot find EOF on input stream."
			<< endl;
	}
	else {
		return;
	}

	exit(1);
}

/*
	*PRECONDICIONES: 
	*POSCONDICIONES: Devuelve True cuando al procesar la entrada se encuentra un error.
*/
bool process_input(istream *is, ostream *os, size_t precision){
	Bignum x, y ,z;
	char op;
	
	while (!is->eof()){
		*is >> x >> op >> y;
		check_precision(x, y, precision);
		validate_opts(op);
		
		*os << do_math(x, y, op) << endl;
	}

	check_stream(is, os);
	
	return false;
}