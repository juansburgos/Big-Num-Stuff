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
/*
	cout << "salida Z: " << z << endl;

	if(x>y) {
		cout << "X > Y" << endl;
	}
	else {
		cout << "X <= Y" << endl;
	}
	
	z = x + y;
	cout << "Z = X + Y = " << x << " + " << y << " = " << z << endl << endl;

	z = y + x;
	cout << "Z = Y + X = " << y << " + " << x << " = "  << z << endl << endl;

	z = x - y;
	cout << "Z = X - Y = " << x << " - " << y << " = "  << z << endl << endl;

	z = y - x;
	cout << "Z = Y - X = " << y << " - " << x << " = "  << z << endl << endl;
*/
    z = x*y;

    cout << z << endl;
	return 0;
}
