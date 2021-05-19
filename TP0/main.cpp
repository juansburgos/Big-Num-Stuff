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

///***** Función main **********************************************************/
//int main(int argc, char const *argv[]){
//
//	const string a = "00000";
//	const string b = "-1323";
//	const string c = "-00000199";
//
//	Bignum x(a),y(b),z,w(c);
//
//	cout << "salida X: " << x << endl;
//	cout << "salida Y: " << y << endl;
//	cout << "salida Z: " << z << endl;
//	cout << "salida w: " << w << endl;
//
//	z = x;
//	cout << "salida Z: " << z << endl;
//	z = x + y ;
//	cout << "salida Z = x+y: " << z << endl;
//
//	z = x - y ;
//	cout << "salida Z = x-y: " << z << endl;
//
//	z = x*y;
//
//	cout << "salida Z = x*y: " << z << endl;
//	return 0;
//}
