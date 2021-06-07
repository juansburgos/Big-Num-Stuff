#ifndef _BIGNUM_H_INCLUDED_
#define _BIGNUM_H_INCLUDED_

#include <iostream>
#include <string>
#include "utils.h"

using namespace std;

//Creo un diccionario para recordar los comandos validos
enum ALLOW_OPTS { SPACE = 0, BF, BN, BR, BT, BV};
const char allow_opt[] = { ' ', '\f', '\r', '\t', '\v' };

//Def de clases
class bignum{
private:
	bool sign; //false es + y true es -//
	size_t size; //cantidad de digitos
	unsigned short *digits;

public:




	bignum();
	bignum(const bool &sign,const size_t &size,const unsigned short *digits);
	bignum(const string& n);
	bignum(const bignum&);

	~bignum();

	//Seters
	void set_virtual_operator(size_t i);

	//Geters
	const size_t & get_size() const { return size; }
	const size_t get_digit(size_t i) const { return digits[i]; }
	const bool & get_sign() const { return sign; }


	//Operadores
	bignum const& operator=(const bignum&);
	friend bignum operator+(const bignum&, const bignum&);
	friend bignum operator-(const bignum&, const bignum&);
	virtual bignum operator*(const bignum&);

	friend ostream& operator<<(ostream&, const bignum&);
	friend istream& operator>>(istream&, bignum&);

	friend bool operator>(const bignum&, const bignum&);
	friend bool operator<(const bignum&, const bignum&);
	friend bool operator==(const bignum&, const bignum&);


	//Virtual
	

	//Funciones
	bignum mult_karatsuba(const bignum&b1, const bignum&b2);
	bignum mult_standard(const bignum&b1, const bignum&b2);


	//Métodos auxiliares
	bool isEmpty() const;
	
};



#endif
