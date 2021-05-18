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

static size_t ok_tests=0;
static size_t total_test=0;

//Mensajes stdout for tests
void ps();
void wellcome();
void test_score();
void print_results();

#endif
