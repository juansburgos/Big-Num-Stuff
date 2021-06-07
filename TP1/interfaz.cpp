#include <iostream>
#include <cmath>
#include "bignum.h"

using namespace std;

/*
class interfaz : public bignum {
    public:
    virtual ~interfaz(){};
    virtual void foo(bignum n)=0;
    virtual bignum multiplicacion(const bignum &b1, const bignum &b2)=0;

};
*/

class standard : public bignum {
	public:
    virtual ~standard(){};
    virtual bignum operator*(const bignum& b2){
        bignum b1 = *this;

        if(b1.get_size() == 0 || b2.get_size() == 0){
            bignum zero("0");
            return zero;
        }

        bool signo;
        size_t tam (b1.get_size()+ b2.get_size());
        unsigned short carry = 0, *auxdig = new unsigned short [tam]{0};

        for(int i = b2.get_size()-1; i >= 0; i--){
            carry = 0;
            for(int h = b1.get_size()-1; h >= 0; h--){
                auxdig[i+h+1] += (carry + b2.get_digit(i) * b1.get_digit(h));
                carry = auxdig[i+h+1] / 10;
                auxdig[i+h+1] = auxdig[i+h+1] % 10;
            }
            auxdig[i] = carry;
        }
        signo = !(b1.get_sign() == b2.get_sign());

        bignum nuevo(signo, tam, auxdig);
        delete [] auxdig;
        return nuevo;    
        }
};
/*
class karatsuba : public bignum {
	public:
    virtual ~karatsuba(){};
    virtual bignum operator*(const bignum& b2){
        
    }
};
*/