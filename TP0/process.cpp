#include "Bignum.h"
#include "process.h"
#include <iostream>

bool process_input(istream *is, ostream *os, size_t precision){

	Bignum x, y ,z;
	char op;

	while (!is->eof()){
		*is >> x >> op >> y;
		if (((x.get_size()) > precision) || ((y.get_size()) > precision)){
			cerr << "Incorrect precision"
				<< endl;
			return false;
		}
		if(op == '+'){
			*os << x + y << endl;
		}
		else if(op == '-'){
			*os << x - y << endl;
		}
		else if(op == '*'){
			*os << x * y << endl;
		}
		else{
			cerr << "Incorrect operator"
				<< endl;
			return false;
		}
		x = z;
		y = z;

	}

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
