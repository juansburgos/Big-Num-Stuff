#ifndef _BIGNUM_H_INCLUDED_
#define _BIGNUM_H_INCLUDED_

#include <iostream>
#include <string>
using namespace std;
//Def de clases

class bignum{
private:
	bool sign; //false es + y true es -//
	unsigned short *digits;
	size_t size; /*cantidad de digitos sin signo*/

public:
	bignum();
	bignum(const bool &sign,const size_t &size,const unsigned short *digits);
	bignum(const string& n);
	bignum(const bignum&);


	friend void print_bignum(bignum const &bn);/*Para probar datos cargados(BORRAR)*/

	bignum const & operator=(const bignum&);
	friend bignum operator+(const bignum&, const bignum&);
	friend bignum operator-(const bignum&, const bignum&);
	friend bignum operator*(const bignum&, const bignum&);
	friend bool operator>(const bignum&, const bignum&);

	friend ostream& operator<<(ostream&, const bignum&);
	friend istream& operator>>(istream&, bignum&);

	~bignum();
};

#endif