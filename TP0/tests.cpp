#include "tests.h"

//Printea separador
void ps(){
	cout << "================================================" << endl;
}

//Printeo bievenida
void wellcome(){
	ps();
	cout << "TESTING..." << endl;
	ps();
}

void test_score(){
	cout << "Test: " << ok_tests << "/" << total_test << endl;
}

void print_results(){
	cout << "<ALL TESTS>" << endl;
	test_score();
}

//Estructura de un TEST
void TEST(bool (*f)()){

	total_test++;
	cout << "<Test " << total_test <<">" << endl;

	if(f() == true) {
		ok_tests++;
	}

	test_score();
	ps();
}

//Creo un test para probar asignacion =
bool test_equal_operator1(){
	const string a = "-145";
	const string b = "323";
	Bignum x(a),y(b),z;

	z = x;
	cout << "z == x" << endl;
	return z == x; //Si no se utiliza assert, utilizar error=False.
}

//Creo un test para probar multiple asignacion = =
bool test_equal_operator2(){
	const string a = "-145";
	const string b = "323";
	Bignum x(a),y(b),z;

	z = x = y;
	cout << "x == y" << endl;
	cout << "z == x" << endl;
	cout << "x == y" << endl;
	return (z == x) && (z == y); //Si no se utiliza assert, utilizar error=False.
}

//Creo un test para probar el operador >
bool test_major(){
	const string a = "20";
	const string b = "150";
	Bignum x(a),y(b);

	cout << "y > x" << endl;
	return (y > x) && !(x > y); //Si no se utiliza assert, utilizar error=False.
}

//Test 1 para probar operadores + y -
bool test_plus_minus_operators1(){
	const string a = "-145";
	const string b = "323";
	const string res = "178";
	Bignum x(a),y(b),r(res),z;

	z = x + y;

	cout << "z = x + y" << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 2 para probar operadores + y -
bool test_plus_minus_operators2(){
	const string a = "-145";
	const string b = "323";
	const string res = "178";
	Bignum x(a),y(b),r(res),z;

	z = y + x;

	cout << "z = y + x" << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 3 para probar operadores + y -
bool test_plus_minus_operators3(){
	const string a = "-145";
	const string b = "323";
	const string res = "-468";
	Bignum x(a),y(b),r(res),z;

	z = x - y;

	cout << "z = " << x << " - " << y << " = " << z << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 4 para probar operadores + y -
bool test_plus_minus_operators4(){
	const string a = "-145";
	const string b = "323";
	const string res = "468";
	Bignum x(a),y(b),r(res),z;

	z = y - x;

	cout << "z = " << y << " - " << x << " = " << z << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 5 para probar operadores + y -
bool test_plus_minus_operators5(){
	const string a = "99";
	const string b = "10";
	const string res = "109";
	Bignum x(a),y(b),r(res),z;

	z = x + y;

	cout << "z = " << x << " + " << y << " = " << z << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 6 para probar operadores + y -
bool test_plus_minus_operators6(){
	const string a = "123";
	const string b = "10";
	const string res = "133";
	Bignum x(a),y(b),r(res),z;

	z = x + y;

	cout << "z = " << x << " + " << y << " = " << z << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 7 para probar operadores + y -
bool test_plus_minus_operators7(){
	const string a = "10";
	const string b = "123";
	const string res = "133";
	Bignum x(a),y(b),r(res),z;

	z = x + y;

	cout << "z = " << x << " + " << y << " = " << z << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 8 para probar operadores + y -
bool test_plus_minus_operators8(){
	const string a = "120";
	const string b = "50";
	const string res = "70";
	Bignum x(a),y(b),r(res),z;

	z = x - y;

	cout << "z = " << x << " - " << y << " = " << z << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 9 para probar operadores + y -
bool test_plus_minus_operators9(){
	const string a = "50";
	const string b = "120";
	const string res = "-70";
	Bignum x(a),y(b),r(res),z;

	z = x - y;

	cout << "z = " << x << " - " << y << " = " << z << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 1 para probar el operador *
bool test_multiplication_operator1(){
	const string a = "50";
	const string b = "120";
	const string res = "6000";
	Bignum x(a),y(b),r(res),z;

	z = x * y;

	cout << "z = " << x << " * " << y << " = " << z << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 2 para probar el operador *
bool test_multiplication_operator2(){
	const string a = "-50";
	const string b = "120";
	const string res = "-6000";
	Bignum x(a),y(b),r(res),z;

	z = x * y;

	cout << "z = " << x << " * " << y << " = " << z << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 3 para probar el operador *
bool test_multiplication_operator3(){
	const string a = "-50";
	const string b = "0";
	const string res = "0";
	Bignum x(a),y(b),r(res),z;

	z = x * y;

	cout << "z = " << x << " * " << y << " = " << z << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 1 para probar los operadores >> y <<
bool test_in_out_operators(){
	const string a = "2016";
	const string b = "-156";
	Bignum x(a),y(b),w, z;

	cout << "Ingrese 2016 -156: " << endl;
	cin >> w >> z;

	return ((w == x) && (z == y)); //Si no se utiliza assert, utilizar error=False.
}

int main(int argc, char const *argv[]){
	/*
	COMPILACION: make all_test

	INFO:
	Acá se va agregar todos los test que necesitemos probar.
	La idea es que queden para siempre cosa que cuando avancemos en el proyecto
	si tenemos algún bug lo podamos detectar fácil.
	ok_test: Mide la cantidad de test que no fallaron.
	total_test: Cuando se agrega más test, éste número incrementa sólo.
	*/
	wellcome();

	TEST(test_equal_operator1);
	TEST(test_equal_operator2);
	TEST(test_major);
	TEST(test_plus_minus_operators1);
	TEST(test_plus_minus_operators2);
	TEST(test_plus_minus_operators3);
	TEST(test_plus_minus_operators4);
	TEST(test_plus_minus_operators5);
	TEST(test_plus_minus_operators6);
	TEST(test_plus_minus_operators7);
	TEST(test_plus_minus_operators8);
	TEST(test_plus_minus_operators9);
	TEST(test_multiplication_operator1);
	TEST(test_multiplication_operator2);
	TEST(test_multiplication_operator3);
	TEST(test_in_out_operators);

	print_results();
}
