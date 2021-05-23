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
#include <fstream>
#include <iomanip>
#include <sstream>



/***** Bibliotecas Propias ***************************************************/
#include "cmdline.h"
#include "bignum.h"
#include "utils.h"
#include "process.h"

/***** Elementos Globales ****************************************************/
using namespace std;


/***** CMDLINE config ********************************************************/

static void opt_input(string const &);
static void opt_output(string const &);
static void opt_precision(string const &);
static void opt_help(string const &);

static option_t options[] = {
	{1, "i", "input", "-", opt_input, OPT_DEFAULT},
	{1, "o", "output", "-", opt_output, OPT_DEFAULT},
	{1, "p", "precision", NULL, opt_precision, OPT_MANDATORY}, /*opt_precision*/
	{0, "h", "help", NULL, opt_help, OPT_DEFAULT},
	{0, },
};
static size_t precision;
static istream *iss = 0;
static ostream *oss = 0;
static fstream ifs;
static fstream ofs;

static void
opt_input(string const &arg)
{
	// Si el nombre del archivos es "-", usaremos la entrada
	// est�ndar. De lo contrario, abrimos un archivo en modo
	// de lectura.
	//
	if (arg == "-") {
		iss = &cin;
	} else {
		ifs.open(arg.c_str(), ios::in);
		iss = &ifs;
	}

	// Verificamos que el stream este OK.
	//
	if (!iss->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}

static void
opt_output(string const &arg)
{
	// Si el nombre del archivos es "-", usaremos la salida
	// est�ndar. De lo contrario, abrimos un archivo en modo
	// de escritura.
	//
	if (arg == "-") {
		oss = &cout;
	} else {
		ofs.open(arg.c_str(), ios::out);
		oss = &ofs;
	}

	// Verificamos que el stream este OK.
	//
	if (!oss->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}

static void
opt_precision(string const &arg)
{
	istringstream iss(arg);

	// Intentamos extraer el factor de la l�nea de comandos.
	// Para detectar argumentos que �nicamente consistan de
	// n�meros enteros, vamos a verificar que EOF llegue justo
	// despu�s de la lectura exitosa del escalar.
	//
	if (!(iss >> precision)
	    || !iss.eof()) {
		cerr << "non-integer precision: "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}

	if (iss.bad()) {
		cerr << "cannot read integer precision."
		     << endl;
		exit(1);
	}
}

static void
opt_help(string const &arg)
{
	cout << "cmdline -p precision [-i file] [-o file]"
	     << endl;
	exit(0);
}


/***** Función main **********************************************************/
int main(int argc, char * const argv[]){

	cmdline cmdl(options);
	cmdl.parse(argc, argv);
	
	if (process_input(iss,oss,precision) == false){
		return 1;
	}
	
	
	return 0;
}
