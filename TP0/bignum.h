#ifndef _BIGNUM_H_INCLUDED_
#define _BIGNUM_H_INCLUDED_

#include <iostream>
#include <string>
    
//Def de clases

class bignum{
    private:
        bool sign; //false es + y true es -//
        unsigned short *digits;
        size_t size; /*cantidad de digitos sin signo*/

    public:
        bignum();
        bignum(string const );
        bignum(bignum const &);
        

        friend void print_bignum(bignum const &bn);/*Para probar datos cargados*/
        bignum const &operator=(const bignum&);

        /*
        friend bignum operator+(const bignum&, const bignum&);
        friend bignum operator-(const bignum&, const bignum&);
        friend bignum operator*(const bignum&, const bignum&);
        friend std::ostream& operator<<(std::ostream&, const bignum&);
        friend std::istream& operator>>(std::istream&, bignum&);*/

        ~bignum();
};

#endif