#include <iostream>
#include "producto.h"
#include "bignum.h"

bignum standard::multi(const bignum& b1, const bignum& b2)const {
    return b1*b2;
}

bignum karatsuba::multi(const bignum& b1, const bignum& b2)const {
    if((b1.get_size() == 1 && b1.get_digit(0) == 0) || (b2.get_size() == 1 && b2.get_digit(0) == 0)) {
		bignum zero("0");
		return zero;
	}

	bool signo;
	signo = !(b1.get_sign() == b2.get_sign());

	if(b1.get_size() == 1 && b2.get_size() == 1) {
		unsigned short *aux_nuevo = new unsigned short [2]{0};
		aux_nuevo[0] = (b1.get_digit(0) * b2.get_digit(0))/10;
		aux_nuevo[1] = (b1.get_digit(0) * b2.get_digit(0))%10;
		bignum nuevo(signo, 2, aux_nuevo);
        delete [] aux_nuevo;
		return nuevo;
	}

	// Busco el exponente como el tamaño más grande dividido 2
	size_t m;
	if(b1.get_size() >= b2.get_size()) {
		m = b1.get_size() / 2;
		if(b1.get_size() % 2) {
			m++;
		}
	}
	else {
		m = b2.get_size()/2;
		if(b2.get_size() % 2) {
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
		auxb1_1[m-i-1] = (b1.get_size() > m && b1.get_size()-m-1 >= i) ? b1.get_digit(b1.get_size()-m-i-1) : 0;
		auxb2_1[m-i-1] = (b2.get_size() > m && b2.get_size()-m-1 >= i) ? b2.get_digit(b2.get_size()-m-i-1) : 0;
		auxb1_0[m-i-1] = (b1.get_size()-1 >= i) ? b1.get_digit(b1.get_size()-i-1) : 0;
		auxb2_0[m-i-1] = (b2.get_size()-1 >= i) ? b2.get_digit(b2.get_size()-i-1) : 0;
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
	unsigned short *auxz2_1 = new unsigned short [(2*m)+z2.get_size()]{0};
	for(size_t i=0; i < z2.get_size(); i++){
		if(i<z2.get_size()) { // Tengo que poner el 0 del exponente
			auxz2_1[i] = z2.get_digit(i);
		}
	}
	z2 = bignum(false, (2*m)+z2.get_size(), auxz2_1);
	delete [] auxz2_1;

	// Calculo z1
	z1 = b1_1*b2_0 + b1_0*b2_1;
	unsigned short *auxz1_1 = new unsigned short [m+z1.get_size()]{0};
	for(size_t i=0; i < z1.get_size(); i++){
		if(i<z1.get_size()) { // Tengo que poner el 0 del exponente
			auxz1_1[i] = z1.get_digit(i);
		}
	}
	z1 = bignum(false, m+z1.get_size(), auxz1_1);
	delete [] auxz1_1;

	// Calculo z0
	z0 = b1_0*b2_0;


	bignum nuevo(z2+z1+z0);
	nuevo.set_sign(signo);
	return nuevo;

}
