#include "benchmark_propio.h"

double benchmark() {
	//Imprimo por cout un cartel e inserto la primer fila de etiquetas en el archivo
	std::cout << "Ejecutando el benchmark..." << std::endl;
	
	double segundos = 0;
	auto start = std::chrono::high_resolution_clock::now();

	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = end - start;

	return std::chrono::duration<double>(elapsed).count();
}
