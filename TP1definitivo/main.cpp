/******************************************************************************
* TP1 - Algoritmos y Programación II                                          *
* Alumnos:                                                                    *
*          Grattan Plunkett, Kevin Anthony - #100487                          *
*          Mokorel Pablo                   - #103029                          *
*          Burgos, Juan Sebastián          - #100113                          *
*          Potenza, Nicolás Alejandro      - # 97024                          *
*                                                                             *
******************************************************************************/

/***** Bibliotecas Propias ***************************************************/
#include "main.h"

/***** Función main **********************************************************/
int main(int argc, char * const argv[]){
	cmdline cmdl(options);
	cmdl.parse(argc, argv);

	cout << method << endl;

	if (process_input(iss, oss) == false){
		return 1;
	}
	
	return 0;
}
