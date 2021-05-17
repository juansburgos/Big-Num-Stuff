/*****************************************************************************
 * TP0 - Algoritmos y Programación II                                        *
 * Alumnos:                                                                  *
 *          Grattan Plunkett, Kevin Anthony - #100487                        *
 *          Mokorel Pablo                   - #103029                        *
 *          Burgos, Juan Sebastián          - #100113                        *
 *          Potenza, Nicolás A.             - # 97024                        *
 *                                                                           *
 *****************************************************************************/

/***** Bibliotecas Estándar **************************************************/
#include <string>
#include <cstdlib>
#include <iostream>
#include <cmath>

/***** Bibliotecas Propias ***************************************************/
#include "cmdline.h"
#include "bignum.h"
#include "bool.h"


/***** Elementos Globales ****************************************************/
using namespace std;

/***** Función main **********************************************************/
int main(int argc, char const *argv[]){
    
    const string a = "-145";
    const string b = "323";

    bignum x(a),y(b),z;
    
    print_bignum(x);
    print_bignum(y);
    print_bignum(z);

    z = x;
    
    print_bignum(z);

    cout << "salida X: " << x << endl;
    cout << "salida Y: " << y << endl;
    cout << "salida Z: " << z << endl;

	return 0;
}