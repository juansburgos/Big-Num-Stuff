#include "bool.h"

bool is_negative(const string &s){

    if (s[0] == '-'){
        return true;
    }
    else{
        return false;
    }  
}