//Función process_input luego de la revisión
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


//Función process_input original
bool process_input(istream *is, ostream *os, size_t precision){
	bignum x, y;
	char op;
	bool st;

	while (*is >> x >> op >> y){
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

	}

	if ((st = check_stream(is, os)) == false){
		return st;
	}
	return true;
}
