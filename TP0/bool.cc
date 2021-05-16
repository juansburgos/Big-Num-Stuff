#include "bool.h"
#include <string>

using namespace std;

bool is_negative(const string &s){

    if (s[0] == '-'){
        return true;
    }
    else{
        return false;
    }  
}