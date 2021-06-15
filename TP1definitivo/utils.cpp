#include "utils.h"

bool validate_dict(const char& op, const char* dict) {
	size_t i ;
	for (i= 0; dict[i] != '\0'; i++) {
		if (dict[i] == op){
		return true;
		}
	}
	return false;
}

bool is_negative(const string &s){
	return s[0] == MINUS;
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
bool is_digits_equal(const unsigned short *a, const unsigned short *b, const size_t &size){

	for(size_t i = 0; i < size; i++){
		if(a[i]!=b[i])
			return false;
	}

	return true;
}