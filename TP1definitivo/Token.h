#ifndef TOKEN__H
#define TOKEN__H

#include <iostream>
#include <string>

#include "bignum.h"

using namespace std;
class Token
{
public:
    enum type_t
    {
        BINARY_OP,
        NUMBER,
        LEFT_PAREN,
        RIGHT_PAREN,
        UNDEFINED};
    enum associativity_t {LEFT, RIGHT, UNDEF};
private:
    string name;
    type_t type; // Tipo del token
    int priority;
    associativity_t associativity;
    void * value; // Puntero al token
public:
    //CONSTRUCTORES:
    Token(); // Por defecto
    Token(string str); // Construye e inicializa parseando
    Token(Token & in); // Constructor copia
    //DESTRUCTOR
    ~Token();

    //Miembros
    void init(string str); // Inicializa y parsea
    void clear(); // Reinicia los atributos del token
    void print(); // Imprime por pantalla el token
    void operator=(Token &input); // Copia
    bignum doBinary(bignum izq, bignum der); // Resuelve el token binario
    bignum getNumber(); // Devuelve el numero

    //Getters
    string getName();
    type_t getType();
    int getPriority();
    associativity_t getAssociativity();
};
#endif
