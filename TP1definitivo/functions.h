/*Archivo functions.h
En este archivo se encuentran definidas todas las funciones que soporta el programa*/
#ifndef FUNCIONES__H
#define FUNCIONES_H

#include <iostream>
#include <cmath>
#include "bignum.h"

//Defino mi tipo de dato puntero a funcion
typedef bignum(*unary_t)(bignum);
typedef bignum(*binary_t)(bignum,bignum);

//Operadores
bignum suma(bignum izq, bignum der);
bignum resta(bignum izq, bignum der);
bignum producto(bignum izq, bignum der);
bignum division(bignum izq, bignum der);

#endif
