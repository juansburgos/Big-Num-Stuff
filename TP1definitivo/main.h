#ifndef __MAIN__
#define __MAIN__

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
static void opt_input(string const&);
static void opt_output(string const&);
static void opt_help(string const&);
static void opt_method(string const&);

static option_t options[] = {
	{1, "m", "method", "-", opt_method, OPT_DEFAULT},
	{1, "i", "input", "-", opt_input, OPT_DEFAULT},
	{1, "o", "output", "-", opt_output, OPT_DEFAULT},
	{0, "h", "help", NULL, opt_help, OPT_DEFAULT},
	{0, },
};

static istream* iss = 0;
static ostream* oss = 0;
static fstream ifs;
static fstream ofs;
static string method;

static void
opt_method(string const& arg)
{
	istringstream iss(arg);
	if (arg == "-") {
		method = "karatsuba";
		return;
	}

	if (!(iss >> method)|| !iss.eof()) {
			cerr << " "
			<< arg
			<< "."
			<< endl;
			exit(1);
	}
		
	if (method != "standard" && method != "karatsuba"){
					cerr << arg
					<< " es un metodo incorrecto "
					<< "."
					<< endl;
					exit(1);
	}

	if (iss.bad()) {
		cerr << "Metodo incorrecto."
			<< endl;
		exit(1);
	}

	method = "standard";
	inter.cambiarEstandar();
}



static void
opt_input(string const& arg)
{
	// Si el nombre del archivos es "-", usaremos la entrada
	// est�ndar. De lo contrario, abrimos un archivo en modo
	// de lectura.
	//
	if (arg == "-") {
		iss = &cin;
	}
	else {
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
opt_output(string const& arg)
{
	// Si el nombre del archivos es "-", usaremos la salida
	// est�ndar. De lo contrario, abrimos un archivo en modo
	// de escritura.
	//
	if (arg == "-") {
		oss = &cout;
	}
	else {
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
opt_help(string const& arg)
{
	cout << "cmdline -m method [-i file] [-o file]"
		<< endl;
	exit(0);
}

#endif