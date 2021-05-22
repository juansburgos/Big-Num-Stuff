#ifndef _BIGNUM_H_INCLUDED_
#define _BIGNUM_H_INCLUDED_

#include <iostream>
#include <string>
using namespace std;
//Def de clases

class Bignum{
private:
	bool sign; //false es + y true es -//
	size_t size; //cantidad de digitos
	unsigned short *digits;

public:
	//Constructores
	Bignum();
	Bignum(const bool &sign,const size_t &size,const unsigned short *digits);
	Bignum(const string& n);
	Bignum(const Bignum&);

	//Destructor por defecto
	~Bignum();

	//Geters
	const size_t & get_size() const { return size; }

	//Operadores
	Bignum const& operator=(const Bignum&);
	friend Bignum operator+(const Bignum&, const Bignum&);
	friend Bignum operator-(const Bignum&, const Bignum&);
	friend Bignum operator*(const Bignum&, const Bignum&);

	friend ostream& operator<<(ostream&, const Bignum&);
	friend istream& operator>>(istream&, Bignum&);

	friend bool operator>(const Bignum&, const Bignum&);
	friend bool operator==(const Bignum&, const Bignum&);
	//Métodos auxiliares
	friend void printBignum(Bignum const &bn);
	bool isEmpty() const;

};

#endif
