#include "process.h"
#include <string>

static Stack<Token> postfixStack;
static string variableName("z");

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


/*La siguiente funcion evalua una expresion matematica ingresada por argumento
PRECONDICIONES: Se debe inizializar la variable global postfixStack, no no funciona
Se debe verificar previamente que la variable compleja a usar sea la misma que la variable
que posee el stack de tokens
POSTCONDICIONES: Devuelve la expresion resuelta*/

void imp_stack_string(Stack<string> aux) {
	while (!aux.empty()) {
		cout << aux.top() << endl;
		aux.pop();
	}
}

/*
	Se ingresa una expresi�n matem�tica para hacer las operaciones correspondientes.
	arg: expresi�n en string: 10+21-(31*100+1)/20
*/
Stack<Token>* process_line(string const& arg) {
	Stack<string>* stk;
	Stack <Token>* TKstk;
	Stack <Token>* shunt; //Creo memoria din�mica.


	string expresion = remove_spaces(arg, WHITESPACES);

	if ((stk = read_math_expression(expresion)) == nullptr)
	{
		cout << "Error al leer la expresion" << endl;
		exit(1);
	}

	if ((TKstk = createStackTokens(stk)) == nullptr)
	{
		cout << "Error al crear stack de tokens" << endl;
		delete stk;
		exit(1);
	}
	delete stk;
	if ((shunt = shunting_yard(TKstk)) == nullptr)
	{
		cout << "Error al crear stack de tokens" << endl;
		delete TKstk;
		exit(1);
	}
	delete TKstk;

	return shunt;
}

//Devuelve true cuando se procesa la entrada satisfactoriamente.
bool process_input(istream *is, ostream *os, string method){
	operaciones *ope;

	if(method == "standard")
		ope = new operaciones (new karatsuba);
	else
		ope = new operaciones (new standard);

	string linea;
	while (getline(*is, linea)){
		if(!isBalanced(linea)){
			cerr << "ERROR: Cadena no balanceada" << endl;
			exit(1);
		}
		Stack<Token>* stk = process_line(linea);
		bignum ans = evalPostfix(stk, ope);
		cout << ans << endl;
		delete stk;
	}
	delete ope;

	return true;
}
