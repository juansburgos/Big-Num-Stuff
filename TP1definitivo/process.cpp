#include "process.h"
#include <string>

static Stack<Token> postfixStack;
static string variableName("z");
static function_t function = nullptr;

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

/*La siguiente funcion valida que el stack de tokens posea
una sola variable y sea varName
PRECONDICIONES: ninguna
POSTCONDICIONES: Devuelve true si la variable esta correcta, false si no */
bool validateVar(const Stack<Token>* stackTK, string varName) {

	Stack<Token> aux = *stackTK; // Se copia el stack para no modificarlo

	while (!aux.empty())
	{
		if (aux.top().getType() == Token::VARIABLE)
		{
			if (aux.top().getName() != varName)// Si hay una variable distinta 
				return false; // false porque solo se permite a varName
		}
		aux.pop();
	}

	return true;
}

/*La siguiente funcion evalua una expresion matematica ingresada por argumento
PRECONDICIONES: Se debe inizializar la variable global postfixStack, no no funciona
Se debe verificar previamente que la variable compleja a usar sea la misma que la variable
que posee el stack de tokens
POSTCONDICIONES: Devuelve la expresion resuelta*/
bignum evaluateExpression(bignum var) {
	Stack<Token> aux(postfixStack);
	return evalPostfix(&aux);;
}

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
	//cout << "=======STRING======" << endl;
	//imp_stack_string(*stk);
	//cout << "<<<<<<TOKENS<<<<<<<" << endl;

	if ((TKstk = createStackTokens(stk)) == nullptr)
	{
		cout << "Error al crear stack de tokens" << endl;
		delete stk;
		exit(1);
	}
	delete stk;

	//En este caso no hay variables Z, entonces como vamos a resolver operaciones. Se tiene que sacar.
	//if (!validateVar(TKstk, variableName)) // Si se ingresa una variable que no es del programa. Tira error.
	//{
	//	cout << "Error no se reconocen variables" << endl;
	//	delete TKstk;
	//	exit(1);
	//}
	//TKstk->print();
	//cout << ">>>>>>>SHUNTING>>>>>>>>" << endl;
	if ((shunt = shunting_yard(TKstk)) == nullptr)
	{
		cout << "Error al crear stack de tokens" << endl;
		delete TKstk;
		exit(1);
	}
	delete TKstk;
	//cout << "====SHUNTING====" << endl;
	//shunt->print();
	//cout << "====================" << endl;
	//postfixStack = *shunt; // se inicializa la variable postfixStack
	//while (!shunt->empty()) {
	//	//cout<< shunt->top().getName() << endl;
	//	shunt->top().print();
	//	shunt->pop();
	//}

	//delete shunt; // Se elimina la memoria dinamica shunt
	//function = evaluateExpression;
	//Necesito devolver la expresi�n matematica para despu�s procesarla en otra funci�n. Tiene que ser memoria din�mica
	return shunt;
}

//Devuelve true cuando se procesa la entrada satisfactoriamente.
bool process_input(istream *is, ostream *os){
	bool st;

	string linea;
	while (getline(*is, linea)){
		//cout << linea << endl;
		//cout << "=============================================" << endl;
		Stack<Token>* stk = process_line(linea);
		//stk->print();

		bignum ans = evalPostfix(stk);
		cout << ans << endl;
		delete stk;
	}
	
	/*if ((st = check_stream(is, os)) == false){
		return st;
	}*/
	return true;
}