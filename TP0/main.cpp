/******************************************************************************
* TP0 - Algoritmos y Programación II                                          *
* Alumnos:                                                                    *
*          Grattan Plunkett, Kevin Anthony - #100487                          *
*          Mokorel Pablo                   - #103029                          *
*          Burgos, Juan Sebastián          - #100113                          *
*          Potenza, Nicolás Alejandro      - # 97024                          *
*                                                                             *
******************************************************************************/

/***** Bibliotecas Estándar **************************************************/
#include <string>
#include <cstdlib>
#include <iostream>
#include <cmath>

/***** Bibliotecas Propias ***************************************************/
#include "cmdline.h"
#include "bignum.h"
#include "utils.h"


/***** Elementos Globales ****************************************************/
using namespace std;

/***** Función main **********************************************************/
int main(int argc, char const *argv[]){

	const string a = "-145";
	const string b = "323";

	Bignum x(a),y(b),z;

	cout << "salida X: " << x << endl;
	cout << "salida Y: " << y << endl;
	cout << "salida Z: " << z << endl;

	z = x;

	cout << "salida Z: " << z << endl;

	z = x*y;

	cout << z << endl;
	return 0;
}
