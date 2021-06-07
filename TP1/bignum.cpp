#include "bignum.h"
#include "utils.h"
#include "interfaz.cpp"
#include <iostream>
#include <cmath>

using namespace std;

bignum::bignum(){
	sign = false;
	size = 0;
	digits = nullptr;
}

bignum::bignum(const bool &_sign,const size_t &_size,const unsigned short *_digits) {

	sign = _sign;
	size_t z = zerocount(_digits, _size);

	if ( z == _size ){
		size = 1;
		sign = false;
		digits = new unsigned short[size];
		*digits = 0 ;
	}
	else{
		size = _size-z;
		digits = new unsigned short[size];
		for(size_t i = 0; i < size; i++) {
			digits[i] = _digits[i+z];
		}
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
		if( isdigit(n[i+begin]) == false ){
			exit(1);
		}
		digits[i] = n[i+begin] - '0';
	}

}

bignum::bignum(const bignum &b) {
	sign = b.sign;
	size = b.size;
	digits = new unsigned short[size];

	for (size_t i = 0; i < size; i++){
		digits[i] = b.digits[i];
	}
}

bignum::~bignum(){
	if (digits==nullptr){
		return;
	}
	delete[] digits;
}

bignum const& bignum::operator=(const bignum &b){
	sign = b.sign;
	size = b.size;

	if(this==&b){
		return *this;
	}
	if (digits){
		delete [] digits;
	}
	digits = new unsigned short[size];

	for (size_t i = 0; i < size; i++){
		digits[i] = b.digits[i];
	}
	return *this;
}

bignum operator+(const bignum &b1, const bignum &b2){
	bignum nuevo;
	if(b1.sign != b2.sign) {
		if(b1.sign == true) {
			bignum _b1(b1);
			_b1.sign = !b1.sign;
			nuevo = b2-_b1;
		}
		else {
			bignum _b2(b2);
			_b2.sign = !b2.sign;
			nuevo = b1-_b2;
		}
	}
	else {
		bool sign = b1.sign;
		size_t size = (b1.size >= b2.size)?b1.size+1:b2.size+1;
		unsigned short *digits = new unsigned short[size];
		unsigned short carry = 0;

		for (size_t i = 1; i <= size; i++) {
			if (b1.size-i > size) {
				if(b2.size-i > size) {
					digits[size-i] = carry;
					carry = 0;
				}
				else {
					digits[size-i] = (b2.digits[b2.size-i] + carry)%10;
					carry = (b2.digits[b2.size-i] + carry)/10;
				}
			}
			else if(b2.size-i > size){
				digits[size-i] = (b1.digits[b1.size-i] + carry)%10;
				carry = (b1.digits[b1.size-i] + carry)/10;
			}
			else{
				digits[size-i] = (b1.digits[b1.size-i] + b2.digits[b2.size-i] + carry)%10;
				carry = (b1.digits[b1.size-i] + b2.digits[b2.size-i] + carry)/10;
			}
		}
		nuevo = bignum(sign,size,digits);
		delete[] digits;
	}
	return nuevo;
}

bignum operator-(const bignum &b1, const bignum &b2){
	bignum nuevo;
	if(b2>b1){
		nuevo = b2-b1;
		nuevo.sign = !nuevo.sign;
	}
	else if(b2.sign == true){
		bignum _b2(b2);
		_b2.sign = !b2.sign;
		nuevo = b1 + _b2;
	}
	else if(b1.sign == true){
		bignum _b1(b1);
		_b1.sign = !b1.sign;
		nuevo = _b1+b2;
		nuevo.sign = !nuevo.sign;
	}
	else{
		bool sign = b1.sign;
		size_t size = (b1.size >= b2.size)?b1.size:b2.size;
		unsigned short *digits = new unsigned short[size];
		short carry = 0;

		for (size_t i = 1; i <= size; i++) {
			if(b1.size-i > size) {
				digits[size-i] = 10 - (b2.digits[b2.size-i] + carry);
				carry = 1;
			}
			else if(b2.size-i > size) {
				if(b1.digits[b1.size-i] < carry) {
					digits[size-i] = (b1.digits[b1.size-i]+10) - carry;
					carry = 1;
				}
				else {
					digits[size-i] = b1.digits[b1.size-i] - carry;
					carry = 0;
				}
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
		if(carry == 1) {
			sign = !sign;
		}
		nuevo = bignum(sign,size,digits);
		delete[] digits;
	}
	return nuevo;
}

bignum bignum::mult_karatsuba(const bignum&b1, const bignum&b2){
	if((b1.size == 1 && b1.digits[0] == 0) || (b2.size == 1 && b2.digits[0] == 0)) {
		bignum zero("0");
		return zero;
	}

	bool signo;
	signo = !(b1.sign == b2.sign);

	if(b1.size == 1 && b2.size == 1) {
		unsigned short *aux_nuevo = new unsigned short [2]{0};
		aux_nuevo[0] = (b1.digits[0] * b2.digits[0])/10;
		aux_nuevo[1] = (b1.digits[0] * b2.digits[0])%10;
		bignum nuevo(signo, 2, aux_nuevo);
		return nuevo;
	}

	// Busco el exponente como el tamaño más grande dividido 2
	size_t m;
	if(b1.size >= b2.size) {
		m = b1.size / 2;
		if(b1.size % 2) {
			m++;
		}
	}
	else {
		m = b2.size/2;
		if(b2.size % 2) {
			m++;
		}
	}

	// Parto los números
	unsigned short *auxb1_1 = new unsigned short [m]{0};
	unsigned short *auxb1_0 = new unsigned short [m]{0};
	unsigned short *auxb2_1 = new unsigned short [m]{0};
	unsigned short *auxb2_0 = new unsigned short [m]{0};

	// Creo los fragmentos para hacer las operaciones
	for(size_t i=0; i < m; i++){
		auxb1_1[m-i-1] = (b1.size > m && b1.size-m-1 >= i) ? b1.digits[b1.size-m-i-1] : 0;
		auxb2_1[m-i-1] = (b2.size > m && b2.size-m-1 >= i) ? b2.digits[b2.size-m-i-1] : 0;
		auxb1_0[m-i-1] = (b1.size-1 >= i) ? b1.digits[b1.size-i-1] : 0;
		auxb2_0[m-i-1] = (b2.size-1 >= i) ? b2.digits[b2.size-i-1] : 0;
	}

	bignum b1_1(false, m, auxb1_1);
	bignum b2_1(false, m, auxb2_1);
	bignum b1_0(false, m, auxb1_0);
	bignum b2_0(false, m, auxb2_0);

	delete [] auxb1_0;
	delete [] auxb1_1;
	delete [] auxb2_0;
	delete [] auxb2_1;

	// Hago las operaciones parciales
	bignum z2, z1, z0;

	// Calculo z2
	z2 = b1_1*b2_1;
	unsigned short *auxz2_1 = new unsigned short [(2*m)+z2.size]{0};
	for(size_t i=0; i < z2.size; i++){
		if(i<z2.size) { // Tengo que poner el 0 del exponente
			auxz2_1[i] = z2.digits[i];
		}
	}
	z2 = bignum(false, (2*m)+z2.size, auxz2_1);
	delete [] auxz2_1;

	// Calculo z1
	z1 = b1_1*b2_0 + b1_0*b2_1;
	unsigned short *auxz1_1 = new unsigned short [m+z1.size]{0};
	for(size_t i=0; i < z1.size; i++){
		if(i<z1.size) { // Tengo que poner el 0 del exponente
			auxz1_1[i] = z1.digits[i];
		}
	}
	z1 = bignum(false, m+z1.size, auxz1_1);
	delete [] auxz1_1;

	// Calculo z0
	z0 = b1_0*b2_0;


	bignum nuevo(z2+z1+z0);
	nuevo.sign = signo;
	return nuevo;
}



bignum bignum::mult_standard(const bignum&b1, const bignum&b2){
	if(b1.size == 0 || b2.size == 0){
		bignum zero("0");
		return zero;
	}

	bool signo;
	size_t tam (b1.size + b2.size);
	unsigned short carry = 0, *auxdig = new unsigned short [tam]{0};

	for(int i = b2.size-1; i >= 0; i--){
		carry = 0;
		for(int h = b1.size-1; h >= 0; h--){
			auxdig[i+h+1] += (carry + b2.digits[i] * b1.digits[h]);
			carry = auxdig[i+h+1] / 10;
			auxdig[i+h+1] = auxdig[i+h+1] % 10;
		}
		auxdig[i] = carry;
	}
	signo = !(b1.sign == b2.sign);

	bignum nuevo(signo, tam, auxdig);
	delete [] auxdig;
	return nuevo;
}

/*

bignum operator*(const bignum&b1, const bignum&b2){

	if(b1.size == 0 || b2.size == 0){
		bignum zero("0");
		return zero;
	}

	bool signo;
	size_t tam (b1.size + b2.size);
	unsigned short carry = 0, *auxdig = new unsigned short [tam]{0};

	for(int i = b2.size-1; i >= 0; i--){
		carry = 0;
		for(int h = b1.size-1; h >= 0; h--){
			auxdig[i+h+1] += (carry + b2.digits[i] * b1.digits[h]);
			carry = auxdig[i+h+1] / 10;
			auxdig[i+h+1] = auxdig[i+h+1] % 10;
		}
		auxdig[i] = carry;
	}
	signo = !(b1.sign == b2.sign);

	bignum nuevo(signo, tam, auxdig);
	delete [] auxdig;
	return nuevo;
}

bignum operator*(const bignum&b1, const bignum&b2){
	
};
*/

bool operator>(const bignum &b1, const bignum &b2){
	if(b1.sign == true && b2.sign == false) {
		return false;
	}
	else if(b1.sign == false && b2.sign == true) {
		return true;
	}
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
		if (b1.digits[i] == b2.digits[i])
		continue;

		return (b1.digits[i] < b2.digits[i]) ? b1.sign: !b1.sign;
	}
	return false;
}

bool operator<(const bignum& b1, const bignum& b2) {
	if (b1 == b2)
	return false;
	return !(b1 > b2);
}

ostream& operator<<(ostream &out, const bignum &b) {
	if(b.size==0){
		out << "0";
	}
	if(b.sign) out << '-';
	for (size_t i = 0; i < b.size; i++){
		out << b.digits[i];
	}
	return out;
}

istream& operator>>(istream &in, bignum &b){
	bool signo = false;
	unsigned char c;
	bignum n;

	c = in.get();
	while(!in.eof()){
		if (isdigit(c))
		n = n * bignum("10") + bignum(string(1, c));
		else if (n.isEmpty()) {
			if (c == '-')
			signo = true;
		}
		else{
			in.putback(c);
			break;
		}
		c = in.get();
	}
	n.sign = signo;
	b = n;
	return in;
}

bool operator==(const bignum &a, const bignum &b){
	if (a.isEmpty() && b.isEmpty()) {
		return true;
	}
	if (a.isEmpty() || b.isEmpty()) {
		return false;
	}
	return (a.size == b.size) && is_digits_equal(a.digits, b.digits, a.size) && (a.sign == b.sign);
}

bool bignum::isEmpty() const {
	return this->digits == nullptr;
}







/*
class karatsuba : public operacion{
	public:
	virtual ~karatsuba(){};
	virtual bignum operator*(const bignum&b1, const bignum&b2){
			
		if(b1.size == 0 || b2.size == 0){
			bignum zero("0");
			return zero;
		}

		bool signo;
		size_t tam (b1.size + b2.size);
		unsigned short carry = 0, *auxdig = new unsigned short [tam]{0};

		for(int i = b2.size-1; i >= 0; i--){
			carry = 0;
			for(int h = b1.size-1; h >= 0; h--){
				auxdig[i+h+1] += (carry + b2.digits[i] * b1.digits[h]);
				carry = auxdig[i+h+1] / 10;
				auxdig[i+h+1] = auxdig[i+h+1] % 10;
			}
			auxdig[i] = carry;
		}
		signo = !(b1.sign == b2.sign);

		bignum nuevo(signo, tam, auxdig);
		delete [] auxdig;
		return nuevo;

	};	
};


*/



/*

class bignum {
	private:
	interfaz _standard, *operacion=_standard; // Esto está mal
	public:
	bignum(interfaz *interfaz = _standard);
	bignum(const bool &sign,const size_t &size,const unsigned short *digits, *interfaz = _standard);
	bignum(const string& n, *interfaz = _standard);
	bignum(const bignum&, *interfaz = _standard);

	friend bignum & operator+(bignum &a, bignum &b);
	friend bignum & operator-(bignum &a, bignum &b);
	friend bignum & operator*(bignum &a, bignum &b) {
		operacion->operator*(a.digits, a.size, b.digits, b.size);
	}
};





class interfaz {
	public:
	virtual unsigned short & operator*(unsigned short &a, size_t a_long, unsigned short &b, size_t b_long) = 0;
	virtual unsigned short & operator/(unsigned short &a, size_t a_long, unsigned short &b, size_t b_long) = 0;
	virtual unsigned short & operator+(unsigned short &a, size_t a_long, unsigned short &b, size_t b_long) = 0;
	virtual unsigned short & operator-(unsigned short &a, size_t a_long, unsigned short &b, size_t b_long) = 0;
};

class multiplicacion_standard: public interfaz {
	public:
	virtual unsigned short & operator*(unsigned short &a, size_t a_long, unsigned short &b, size_t b_long) {
        // Cálculos
    }
};

class multiplicacion_karatsuba: public interfaz {
	public:
	virtual unsigned short & operator*(unsigned short &a, size_t a_long, unsigned short &b, size_t b_long) {
        // Cálculos
    }
};
*/

