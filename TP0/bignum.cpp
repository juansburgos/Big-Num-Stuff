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

	if ( z == _size ){
		size = 0;
		sign = false;
		digits = nullptr;
	}
	else{
		size = _size-z;
		digits = new unsigned short[size];
		for(size_t i = 0; i < size; i++) {
			digits[i] = _digits[i+z];
	}
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
		if( isdigit(n[i+begin]) == false ){
			exit(1);
		}
		digits[i] = n[i+begin] - '0';
	}

}

Bignum::Bignum(const Bignum &b) {
	sign = b.sign;
	size = b.size;
	digits = new unsigned short[size];

	for (size_t i = 0; i < size; i++){
		digits[i] = b.digits[i];
	}
}

Bignum::~Bignum(){
	//Chequeo si digitos es vacio.
	if (digits==nullptr){
		return;
	}
	delete[] digits;
}

Bignum const& Bignum::operator=(const Bignum &b){
	sign = b.sign;
	size = b.size;

	if(this==&b){
		return *this;
	}
	if (digits){
		delete [] digits;
	}
	cout << size << endl;
	digits = new unsigned short[size];

	for (size_t i = 0; i < size; i++){
		digits[i] = b.digits[i];
	}
	return *this;
}

Bignum operator+(const Bignum &b1, const Bignum &b2){
	Bignum nuevo;
	if(b1.sign != b2.sign) {
		if(b1.sign == true) {
			Bignum _b1(b1);
			_b1.sign = !b1.sign;
			nuevo = b2-_b1;
		}
		else {
			Bignum _b2(b2);
			_b2.sign = !b2.sign;
			nuevo = b1-_b2;
		}
	}
	else {
		bool sign = b1.sign;

		size_t size = (b1.size >= b2.size)?b1.size+1:b2.size+1;
		unsigned short *digits = new unsigned short[size];

		// Inicialmente el carry es 0
		unsigned short carry = 0;

		// Calculo la suma
		for (size_t i = 1; i <= size; i++) {
			if (b1.size-i > size) {
				if(b2.size-i > size) {
					digits[size-i] = carry;	// Cargo el resto
					carry = 0;	// Me quedo con el carry para el siguiente
				}
				else {
					digits[size-i] = (b2.digits[b2.size-i] + carry)%10;	// Cargo el resto
					carry = (b2.digits[b2.size-i] + carry)/10;	// Me quedo con el carry para el siguiente
				}
			}
			else if(b2.size-i > size){
				digits[size-i] = (b1.digits[b1.size-i] + carry)%10;	// Cargo el resto
				carry = (b1.digits[b1.size-i] + carry)/10;	// Me quedo con el carry para el siguiente
			}
			else{
				digits[size-i] = (b1.digits[b1.size-i] + b2.digits[b2.size-i] + carry)%10;	// Cargo el resto
				carry = (b1.digits[b1.size-i] + b2.digits[b2.size-i] + carry)/10;	// Me quedo con el carry para el siguiente
			}
		}
		nuevo = Bignum(sign,size,digits);
		delete[] digits;
	}
	return nuevo;
}

Bignum operator-(const Bignum &b1, const Bignum &b2){
	Bignum nuevo;
	if(b2>b1){
		nuevo = b2-b1;
		nuevo.sign = !nuevo.sign;
	}
	else if(b2.sign == true){
		Bignum _b2(b2);
		_b2.sign = !b2.sign;
		nuevo = b1 + _b2;
	}
	else if(b1.sign == true){
		Bignum _b1(b1);
		_b1.sign = !b1.sign;
		nuevo = _b1+b2;
		nuevo.sign = !nuevo.sign;
	}
	else{
		bool sign = b1.sign;
		size_t size = (b1.size >= b2.size)?b1.size:b2.size;
		unsigned short *digits = new unsigned short[size];

		// Inicialmente el carry es 0
		short carry = 0;

		// Calculo la suma
		for (size_t i = 1; i <= size; i++) {
			if(b1.size-i > size) {
				digits[size-i] = 10 - (b2.digits[b2.size-i] + carry);
				carry = 1;
			}
			else if(b2.size-i > size) {
				digits[size-i] = b1.digits[b1.size-i] - carry;
				carry = 0;
			}
			else if(b1.digits[b1.size-i] < (b2.digits[b2.size-i] + carry)) {
				digits[size-i] = (b1.digits[b1.size-i]+10) - (b2.digits[b2.size-i] + carry);
				carry = 1;
			}
			else {
				digits[size-i] = (b1.digits[b1.size-i] - (b2.digits[b2.size-i] + carry));
				carry = 0;
			}
		}

		// Si el carry es menor que 0
		if(carry == 1) {
			sign = !sign;
		}
		nuevo = Bignum(sign,size,digits);
		delete[] digits;
	}
	return nuevo;
}

Bignum operator*(const Bignum&b1, const Bignum&b2){

	if(b1.size == 0 || b2.size == 0){
		Bignum nuevo("0");
		return nuevo;
	}

	bool signo;
	size_t tamano = (b1.size + b2.size);
	unsigned short carry = 0, *auxdig = new unsigned short [tamano]{0};

	for(int i = b2.size-1; i >= 0; i--){
		carry = 0;
		for(int h = b1.size-1; h >= 0; h--){
			auxdig[i+h+1] += (carry + b2.digits[i] * b1.digits[h]);
			carry = auxdig[i+h+1] / 10;
			auxdig[i+h+1] = auxdig[i+h+1] % 10;
		}
		auxdig[i] = carry;
	}
	if(b1.sign==b2.sign){
		signo = false;
	}
	else{
		signo = true;
	}
	Bignum nuevo(signo, tamano, auxdig);
	delete [] auxdig;
	return nuevo;
}

bool operator>(const Bignum &b1, const Bignum &b2){
	if(b1.sign == true && b2.sign == false) {
		return false;
	}
	else if(b1.sign == false && b2.sign == true) {
		return true;
	}
	//323 es positivo
	else if (b1.sign == false) {
		if(b1.size > b2.size){
			return true;
		}
		else if(b2.size > b1.size){
			return false;
		}
	}
	else if(b1.sign == true) {
		if(b1.size < b2.size){
			return true;
		}
		else if(b2.size < b1.size){
			return false;
		}
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
	if(b.size==0){
		out << "0";
	}
	if(b.sign) out << '-';
	for (size_t i = 0; i < b.size; i++){
		out << b.digits[i];
	}
	return out;
}

istream& operator>>(istream &in, Bignum &b){

	bool signo = false;
	unsigned char c;
	bool is_digit = true;

	c = in.get();
	while(is_digit){
		if((c <= ' ') && (b.size == 0)) {
		}
		else if((c == '-') && (b.size == 0)) {
			signo = true;
		}
		else if(c >= '0' && c <= '9') {
			b = b * Bignum("10") + Bignum(string(1,c));
		}
		else {
			in.putback(c);
			is_digit = false;
			break;
		}
		c = in.get();
	}
	b.sign = signo;
	return in;
}

bool operator==(const Bignum &a, const Bignum &b){
	if (a.isEmpty() && b.isEmpty()) {
		return true;
	}
	if (a.isEmpty() || b.isEmpty()) {
		return false;
	}

	return (a.size == b.size) && is_digits_equal(a.digits, b.digits, a.size) && (a.sign == b.sign);
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

bool Bignum::isEmpty() const {
	return this->digits == nullptr;
}
