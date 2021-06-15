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

/*
bignum potencia(bignum izq, bignum der)
{

    if(izq.getImag() == 0 && der.getImag() == 0){

        return bignum(pow(izq.getReal(), der.getReal()), 0);

    }

    return expz(der * logz(izq)); // izq ^ der = e^(der*ln(izq))
}

bignum Re( bignum comp)
{ 
    return comp.getReal(); //Parte real compleja
}

bignum Im( bignum comp)
{ 
    return comp.getImag(); //Parte imaginaria compleja
}

bignum Abs( bignum comp)
{ 
    return comp.GetModulo(); //Parte imaginaria compleja
}

bignum phase( bignum comp)
{ 
    return comp.GetArg(); //Parte imaginaria compleja
}


//FUNCIONES
bignum expz(bignum z) {
    double x = z.getReal();
    double y = z.getImag();
    return bignum(exp(x) * cos(y), exp(x) * sin(y));
}
bignum cosz(bignum z) {
    double x = z.getReal();
    double y = z.getImag();
    return bignum(cos(x) * cosh(y),-sin(x)*sinh(y));
}
bignum sinz(bignum z) {
    double x = z.getReal();
    double y = z.getImag();
    if(y == 0)
    {
        return bignum(sin(x),0);
    }
    return bignum(sin(x) * cosh(y),cos(x)*sinh(y));
}
bignum logz(bignum z) {
    double mod = z.GetModulo();
    double arg = z.GetArg();
    return bignum(log(mod), arg);
}
*/