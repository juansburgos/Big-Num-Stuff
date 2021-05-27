#ifndef _TESTS_H_INCLUDED_
#define _TESTS_H_INCLUDED_

/***** Bibliotecas Estándar **************************************************/
#include <string>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <assert.h>

/***** Bibliotecas Propias ***************************************************/
#include "cmdline.h"
#include "bignum.h"
#include "utils.h"

using namespace std;

//Mensajes stdout for tests
void ps();
void wellcome();
void test_score();
void print_results();

//Test prototypes
bool test_equal_operator1(); //Creo un test para probar asignacion =
bool test_equal_operator2(); //Creo un test para probar multiple asignacion = =
bool test_major(); //Creo un test para probar el operador >
bool test_minor(); //Creo un test para probar el operador >
bool test_plus_minus_operators1(); //Test 1 para probar operadores + y -
bool test_plus_minus_operators2(); //Test 2 para probar operadores + y -
bool test_plus_minus_operators3(); //Test 3 para probar operadores + y -
bool test_plus_minus_operators4(); //Test 4 para probar operadores + y -
bool test_plus_minus_operators5(); //Test 5 para probar operadores + y -
bool test_plus_minus_operators6(); //Test 6 para probar operadores + y -
bool test_plus_minus_operators7(); //Test 7 para probar operadores + y -
bool test_plus_minus_operators8(); //Test 8 para probar operadores + y -
bool test_plus_minus_operators9(); //Test 9 para probar operadores + y -
bool test_multiplication_operator1(); //Test 1 para probar el operador *
bool test_multiplication_operator2(); //Test 2 para probar el operador *
bool test_multiplication_operator3(); //Test 3 para probar el operador *
bool test_in_out_operators(); //Test 1 para probar los operadores >> y <<
#endif
