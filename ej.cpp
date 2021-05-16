#include <iostream>
#include <cmath>
#include <string>

using namespace std;

//Bool.h 
bool is_negative(const string &s);

//bignum.h
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


//bignum.cpp
//Metodos de clase
// Constructores y destructores

bignum::bignum(){

    sign = 0;
    size = 1;
    digits = new unsigned short[size];
    digits[0] = 0;  

}

bignum::bignum(const string n){

    size_t i,begin = 0;
    sign = false ;

    if (sign = is_negative(n)){
        begin = 1 ;
    }

    size = n.size() - begin;
    digits = new unsigned short[size];

    for ( i = 0; i < size; i++){
        digits[i] = n[i+begin] - '0';      
    }

}

bignum::bignum(const bignum &b) : sign(b.sign),size(b.size),digits(b.digits)
{
}
 
bignum::~bignum(){
    
  if (digits){
        delete [ ] digits;
    }
    
}


bignum const & bignum ::operator=(const bignum& b){

    size_t i;
    sign = b.sign;
    size = b.size;

    digits = new unsigned short[size];

    for (i = 0; i < size; i++){
        digits[i] = b.digits[i];
    }

    return *this; 

}


/*
bignum operator+(const bignum &b1, const bignum &b2){
 

}

bignum operator-(const bignum&, const bignum&){

}

bignum operator*(const bignum&, const bignum&){

}

ostream& operator<<(std::ostream&, const bignum&){

}

istream& operator>>(std::istream&, bignum&){

}
*/


//bool.cpp
bool is_negative(const string &s){

    if (s[0] == '-'){
        return true;
    }
    else{
        return false;
    }  
}

//prueba.cpp
void print_bignum(const bignum &bn){

    if (bn.sign == true){
        cout << '-';
    }
    
    for (size_t i = 0; i < bn.size; i++){
        cout << bn.digits[i];
    }

    cout << endl;
    
}


int main(){

    string a = "-145";
    string b = "323";

    bignum x(a),y(b),z;
    

    print_bignum(x);
    print_bignum(y);
    print_bignum(z);

    z = x;
    
    print_bignum(z);

   
    

}