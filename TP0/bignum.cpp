#include "Bignum.h"
#include "utils.h"
#include <iostream>
#include <cmath>

using namespace std;

/*
	Contructor por defecto.
	PRECONDICIONES: Ninguna.
	POSTCONDICIONES: Como condición empty se setea digits como un puntero nulo.
*/
Bignum::Bignum(){

	sign = false;
	size = 0;
	digits = nullptr;
}

Bignum::Bignum(const bool &_sign,const size_t &_size,const unsigned short *_digits) {
	sign = _sign;
	size_t z = zerocount(_digits, _size);
	size = _size-z;
	digits = new unsigned short[size];
	for(size_t i = 0; i < size; i++) {
		digits[i] = _digits[i+z];
	}
}

Bignum::Bignum(const string& n){

	size_t i,begin = 0;
	sign = false ;

	if ((sign = is_negative(n))){
		begin = 1;
	}

	size = n.size() - begin;
	digits = new unsigned short[size];

	for (i = 0; i < size; i++){
		if(isdigit(n[i+begin])==false){
			exit(1);
		}
		digits[i] = n[i+begin] - '0';
	}

}

Bignum::Bignum(const Bignum &b) : sign(b.sign),digits(b.digits),size(b.size) {}

Bignum::~Bignum(){

	//Chequeo si digitos es vacio.
	if (digits==nullptr){
		return;
	}
	delete [] digits;
}

Bignum& Bignum::operator=(const Bignum &b){

	sign = b.sign;
	size = b.size;

	digits = new unsigned short[size];

	for (size_t i = 0; i < size; i++){
		digits[i] = b.digits[i];
	}

	return *this;
}

/* Falta considerar el caso de que un número sea negativo */
Bignum operator+(const Bignum &b1, const Bignum &b2){

	return Bignum();
}

Bignum operator-(const Bignum&b1, const Bignum&b2){
	Bignum *nuevo = new Bignum();
	if(b2>b1){
		*nuevo = b2-b1;
		nuevo->sign = !nuevo->sign;
	}
	else if(b2.sign == true) {
		Bignum _b2(b2);
		_b2.sign = !b2.sign;
		*nuevo = b1+_b2;
	}
	else if(b1.sign == true) {
		Bignum _b1(b1);
		_b1.sign = !b1.sign;
		*nuevo = _b1+b2;
		nuevo->sign = !nuevo->sign;
	}
	else {
		bool sign = b1.sign;

		size_t size = (b1.size >= b2.size)?b1.size:b2.size;
		unsigned short *digits = new unsigned short[size];

		// Inicialmente el carry es 0
		short carry = 0;

		// Calculo la suma
		for (size_t i = size; i >= 1; i--) {
			if(b1.digits[i-1] < (b2.digits[i-1] + carry)) {
				digits[i-1] = (b1.digits[i-1]+10) - (b2.digits[i-1] + carry);
				carry = 1;
			}
			else {
				digits[i-1] = (b1.digits[i-1] - (b2.digits[i-1] + carry));
				carry = 0;
			}
		}

		// Si el carry es menor que 0
		if(carry == 1) {
			sign = !sign;
		}

		// Armo el Bignum y lo devuelvo
		nuevo = new Bignum(sign,size,digits);
	}
	return *nuevo;
}

Bignum operator*(const Bignum&b1, const Bignum&b2){
	Bignum nuevo;

	return nuevo;
}

bool operator>(const Bignum &b1, const Bignum &b2){
	if(b1.sign == true && b2.sign == false) {
		return false;
	}
	else if(b1.sign == false && b2.sign == true) {
		return true;
	}
	for(size_t i = 0; i < b1.size; i++) {
		if(b1.digits[i] > b2.digits[i]) {
			if(b1.sign == true){
				return false;
			}
			else {
				return true;
			}
		}
		else if(b1.digits[i] < b2.digits[i]) {
			if(b1.sign == true){
				return true;
			}
			else {
				return false;
			}
		}
	}
	return false;
}

ostream& operator<<(ostream &out, const Bignum &b) {

	if(b.sign) out << '-';
	for (size_t i = 0; i < b.size; i++){
		out << b.digits[i];
	}
	return out;

}

istream& operator>>(istream &in, Bignum &b){
	return in;
}

bool operator==(const Bignum &a, const Bignum &b){
	return (a.size == b.size) && is_digits_equal(a.digits, b.digits) && (a.sign == b.sign);
}

void printBignum(const Bignum &bn){ /*Funcion para probar cargas (BORRAR AL TERMINAR)*/

	if (bn.sign == true){
		cout << '-';
	}

	for (size_t i = 0; i < bn.size; i++){
		cout << bn.digits[i];
	}

	cout << endl;

}

bool Bignum::isEmpty(){
	return this->digits == nullptr;
}
