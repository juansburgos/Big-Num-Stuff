/******************************************************************************
* TP0 - Algoritmos y Programación II                                          *
* Alumnos:                                                                    *
*          Grattan Plunkett, Kevin Anthony - #100487                          *
*          Mokorel Pablo                   - #103029                          *
*          Burgos, Juan Sebastián          - #100113                          *
*          Potenza, Nicolás Alejandro      - # 97024                          *
*                                                                             *
******************************************************************************/

/***** Bibliotecas Propias ***************************************************/
#include "main.h"
#include "interfaz.cpp"
/***** Función main **********************************************************/


int main(int argc, char * const argv[]){
	cmdline cmdl(options);
	cmdl.parse(argc, argv);

	bignum b1("10");
	bignum b2("100");

	cout << "b3 = b1 *b2 =" << b1*b2 << endl ;

    bignum * obj1 = new standard();


	cout << "b1:" << b1 << endl;
	cout << "b2:" << b2 << endl;

	cout << "b1:" << b1 << endl;
	cout << "b2:" << b2 << endl;

	delete obj1;

/*	cmdline cmdl(options);
	cmdl.parse(argc, argv);

	if (process_input(iss, oss, precision) == false){
		return 1;
	}
	*/
	return 0;
}
