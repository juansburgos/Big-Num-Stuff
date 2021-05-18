#include "utils.h"

bool is_negative(const string &s){
	if (s[0] == '-'){
		return true;
	}
	else{
		return false;
	}
}

size_t zerocount(const unsigned short *digits, const size_t &size){
	for(size_t i = 0; i < size; i++){
		if(digits[i]!=0){
			return i;
		}
	}
	return size;
}

/*
	PRECONDICIONES: Se pide que los vectores a,b tengan la misma longitud.
	POSCONDICIONES: Devuelve si son iguales o no.
*/
bool is_digits_equal(const unsigned short *a, const unsigned short *b){
	size_t size = sizeof(a)/sizeof(unsigned short);
	for(size_t i = 0; i < size; i++){
		if(a[i]!=b[i])
			return false;
	}

	return true;
}
