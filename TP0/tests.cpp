#include "tests.h"

static size_t ok_tests = 0;
static size_t total_test = 0;

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
	TEST(test_minor);
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
	TEST(test_failed_operators);

	print_results();
}
