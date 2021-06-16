#include <iostream>
#include "producto.h"
#include "bignum.h"

pro::~pro(){}

standard::standard(){}
standard::~standard(){}

bignum standard::multi(const bignum& b1, const bignum& b2)const {
    cout << "aaaa" << endl;
    return b1*b2;
}

karatsuba::karatsuba(){}
karatsuba::~karatsuba(){}
bignum karatsuba::multi(const bignum& b1, const bignum& b2)const {
    cout << "bbbb" << endl;
    return b1*b2;
}
