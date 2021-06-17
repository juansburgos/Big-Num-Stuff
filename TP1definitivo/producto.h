#ifndef _OPERACIONES_H_INCLUDED_
#define _OPERACIONES_H_INCLUDED_
#include "bignum.h"


class pro{
public:
    virtual ~pro(){};
    virtual bignum multi(const bignum&, const bignum&)const=0;
};

class operaciones{
private:
    pro *producto_;
public:
    operaciones(pro *producto = nullptr) : producto_(producto){}
    ~operaciones(){delete this->producto_;};
    bignum multiplicar(const bignum a, const bignum b) const{
        return this->producto_->multi(a, b);
    }
};

class standard : public pro {
public:
    bignum multi(const bignum&, const bignum&)const override;
};

class karatsuba : public pro {
public:
    bignum multi(const bignum&, const bignum&)const override;
};

#endif
