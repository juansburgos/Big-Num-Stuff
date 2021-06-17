/*Archivo functions.cpp*/
#include "functions.h"

//OPERADORES
bignum suma(bignum izq, bignum der){
    return izq + der; // Suma sobrecargada
}

bignum resta(bignum izq, bignum der)
{
    return izq - der;
}

bignum producto(bignum izq, bignum der)
{
    return izq * der; //Producto sobrecargado
}

bignum division( bignum izq, bignum der)
{
    return izq / der; //Division sobrecargada
}
