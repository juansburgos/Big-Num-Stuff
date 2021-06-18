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
#include "benchmark_propio.h"
/***** Función main **********************************************************/
int main(int argc, char * const argv[]){
	cmdline cmdl(options);
	cmdl.parse(argc, argv);

	double segundos = 0;
	auto start = std::chrono::high_resolution_clock::now();

	bool fin = process_input(iss, oss) == false;

	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = end - start;

	segundos = std::chrono::duration<double>(elapsed).count();

	cout << "Tiempo Ejecución: " << segundos << " segundos" << endl;

	return fin;
}
