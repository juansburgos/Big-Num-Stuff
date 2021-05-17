#include "bignum.h"
#include "bool.h"
#include <iostream>
#include <cmath>

using namespace std;

//bignum.cpp
//Metodos de clase
// Constructores y destructores

bignum::bignum(){

	sign = 0;
	size = 1;
	digits = new unsigned short[size];
	digits[0] = 0;

}

bignum::bignum(const string& n){

	size_t i,begin = 0;
	sign = false ;

	if ((sign = is_negative(n))){
		begin = 1 ;
	}

	size = n.size() - begin;
	digits = new unsigned short[size];

	for ( i = 0; i < size; i++){
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


bignum const & bignum::operator=(const bignum& b){

	sign = b.sign;
	size = b.size;

	digits = new unsigned short[size];

	for (size_t i = 0; i < size; i++){
		digits[i] = b.digits[i];
	}

	return *this; 

}


/*
bignum bignum::operator+(const bignum &b1, const bignum &b2){

}

bignum bignum::operator-(const bignum&, const bignum&){

}

bignum bignum::operator*(const bignum&, const bignum&){

}
*/
ostream& operator<<(ostream &out, const bignum &b) {

	if(b.sign) out << '-';
	for (size_t i = 0; i < b.size; i++){
		out << b.digits[i];
	}
	return out;

}
/*
istream& bignum::operator>>(istream &in, bignum &b){
	return in;
}
*/
void print_bignum(const bignum &bn){ /*Funcion para probar cargas (BORRAR AL TERMINAR)*/

	if (bn.sign == true){
		cout << '-';
	}
	
	for (size_t i = 0; i < bn.size; i++){
		cout << bn.digits[i];
	}

	cout << endl;
	
}