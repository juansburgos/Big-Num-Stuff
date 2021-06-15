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
typedef unary_t function_t;

//Operadores
bignum suma(bignum izq, bignum der);
bignum resta(bignum izq, bignum der);
bignum producto(bignum izq, bignum der);
bignum division(bignum izq, bignum der);
bignum potencia(bignum izq, bignum der);
bignum Re( bignum comp);
bignum Im( bignum comp);
bignum Abs( bignum comp);
bignum phase( bignum comp);


//Firmas de funciones
bignum logz(bignum z);
bignum cosz(bignum z);
bignum sinz(bignum z);
bignum expz(bignum z);

#endif