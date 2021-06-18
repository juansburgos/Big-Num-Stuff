#ifndef _OPERACIONES_H_INCLUDED_
#define _OPERACIONES_H_INCLUDED_
#include "bignum.h"

class pro{
public:
    virtual ~pro(){};
    virtual bignum multi(const bignum&, const bignum&)const=0;
};

class standard : public pro {
public:
    bignum multi(const bignum&, const bignum&)const override;
};

class karatsuba : public pro {
public:
    bignum multi(const bignum&, const bignum&)const override;
};

class interfaz {
private:
    pro* producto_;
public:
    interfaz(pro* producto = new karatsuba) : producto_(producto) {}
    interfaz(interfaz& a) {
        producto_ = a.producto_;
    }

    void cambiarEstandar() {
        //delete this->producto_;
        this->producto_ = new standard;
    }

    ~interfaz() { delete this->producto_; };
    bignum multiplicar(const bignum a, const bignum b) const {
        return this->producto_->multi(a, b);
    }

    interfaz& operator=(interfaz& a) {
        producto_ = a.producto_;
        return *this;
    }
};

#endif
