#include "bignum.h"
#include "bool.h"
#include <iostream>
#include <cmath>

using namespace std;

//bignum.cpp
//Metodos de clase
// Constructores y destructores

bignum::bignum(){

	sign = false;
	size = 1;
	digits = new unsigned short[size];
	digits[0] = 0;

}

bignum::bignum(const bool &_sign,const size_t &_size,const unsigned short *_digits) {
	size = _size;
	sign = _sign;
	digits = new unsigned short[size];
	for(size_t i = 0; i < size; i++) {
		digits[i] = _digits[i];
	}
}

bignum::bignum(const string& n){

	size_t i,begin = 0;
	sign = false ;

	if ((sign = is_negative(n))){
		begin = 1;
	}

	size = n.size() - begin;
	digits = new unsigned short[size];

	for (i = 0; i < size; i++){
		digits[i] = n[i+begin] - '0';
	}

}

bignum::bignum(const bignum &b) : sign(b.sign),digits(b.digits),size(b.size) {
}

bignum::~bignum(){
	
	if (digits){
		delete [ ] digits;
	}

}


bignum const & bignum::operator=(const bignum &b){

	sign = b.sign;
	size = b.size;

	digits = new unsigned short[size];

	for (size_t i = 0; i < size; i++){
		digits[i] = b.digits[i];
	}

	return *this;
}


/* Falta considerar el caso de que un número sea negativo */
bignum operator+(const bignum &b1, const bignum &b2){
	bignum *nuevo = new bignum();
	if(b1.sign != b2.sign) {
		if(b1.sign == true) {
			bignum _b1(b1);
			_b1.sign = !b1.sign;
			*nuevo = b2-_b1;
		}
		else {
			bignum _b2(b2);
			_b2.sign = !b2.sign;
			*nuevo = b1-_b2;
		}
	}
	else {
		bool sign = b1.sign; 
		
		size_t size = (b1.size >= b2.size)?b1.size:b2.size;
		unsigned short *digits = new unsigned short[size];
		
		// Inicialmente el carry es 0
		unsigned short carry = 0;

		// Calculo la suma
		for (size_t i = size; i >= 1; i--) {
			// Cargo el resto
			digits[i-1] = (b1.digits[i-1] + b2.digits[i-1] + carry)%10;
			// Me quedo con el carry para el siguiente
			carry = (b1.digits[i-1] + b2.digits[i-1] + carry)/10;
		}

		// Si el carry es 1
		if(carry == 1) {
			unsigned short *digits2 = new unsigned short[size+1];
			// Desplazo
			for (int i = size; i >= 1; i--) {
				digits2[i] = digits[i-1];
			}
			// y Agrego el carry
			digits2[0] = carry;
			// Vuelvo al original
			digits = digits2;
		}

		// Armo el bignum y lo devuelvo
		nuevo = new bignum(sign,size,digits);
	}
	return *nuevo;
}

bignum operator-(const bignum&b1, const bignum&b2){
	bignum *nuevo = new bignum();
	if(b2>b1){
		*nuevo = b2-b1;
		nuevo->sign = !nuevo->sign;
	}
	else if(b2.sign == true) {
		bignum _b2(b2);
		_b2.sign = !b2.sign;
		*nuevo = b1+_b2;
	}
	else if(b1.sign == true) {
		bignum _b1(b1);
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
		
		// Armo el bignum y lo devuelvo
		nuevo = new bignum(sign,size,digits);
	}
	return *nuevo;
}

bignum operator*(const bignum&b1, const bignum&b2){
	bignum *nuevo = new bignum();

	return *nuevo;
}

bool operator>(const bignum &b1, const bignum &b2){
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

ostream& operator<<(ostream &out, const bignum &b) {

	if(b.sign) out << '-';
	for (size_t i = 0; i < b.size; i++){
		out << b.digits[i];
	}
	return out;

}

istream& operator>>(istream &in, bignum &b){
	return in;
}

void print_bignum(const bignum &bn){ /*Funcion para probar cargas (BORRAR AL TERMINAR)*/

	if (bn.sign == true){
		cout << '-';
	}
	
	for (size_t i = 0; i < bn.size; i++){
		cout << bn.digits[i];
	}

	cout << endl;
	
}