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


/***** Elementos Globales ****************************************************/
using namespace std;


/***** CMDLINE config ****************************************************/

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
static int precision;
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
<<<<<<< HEAD

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

void
process_input(istream *is, ostream *os){

	Bignum x, y, z;
	char op;
	string f="46567";

	cin >> x;
	cin >> op;
	cin >> y;
	cin.clear();
	cout << x << endl;
	cout << op << endl;
	cout << y << endl;

	Bignum k(f);
=======

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
/*
void
multiply(istream *is, ostream *os)
{
	int num;

	while (*is >> num) {
		*os << num * factor
		    << "\n";
	}

	if (os->bad()) {
		cerr << "cannot write to output stream."
		     << endl;
		exit(1);
	}
	if (is->bad()) {
		cerr << "cannot read from input stream."
		     << endl;
		exit(1);
	}
	if (!is->eof()) {
		cerr << "cannot find EOF on input stream."
		     << endl;
		exit(1);
	}
}
*/


void
process_input(istream *is, ostream *os){

	string input,num1, num2, op;
	string const delims{ "-+*" };
	
	while (*is >> input){
		size_t beg = 0, pos = 0;
		beg = input.find_first_not_of(delims, pos);

		if ((pos = input.find_first_of(delims, beg + 1)) == string::npos){
			exit(1);
		}
		
		num1 = input.substr(0, pos);
		num2 = input.substr(pos+1, input.size() - pos);
		op = input.at(pos);
		Bignum x(num1),y(num2),z;

		if (op == "+"){
			z = x + y;
		}

		if (op == "-"){
			z = x - y;
		}	

		if (op == "*"){
			z = x * y;
		}

		cout << z << endl;

	}
	
	if (os->bad()) {
		cerr << "cannot write to output stream."
		     << endl;
		exit(1);
	}
	if (is->bad()) {
		cerr << "cannot read from input stream."
		     << endl;
		exit(1);
	}
	if (!is->eof()) {
		cerr << "cannot find EOF on input stream."
		     << endl;
		exit(1);
	}
}




/***** Función main **********************************************************/
int main(int argc, char * const argv[]){
>>>>>>> 8694f4d3ee898246221374ca720739d387abc592

	cmdline cmdl(options);
	cmdl.parse(argc, argv);
	process_input(iss, oss);

<<<<<<< HEAD
	if(op == '+'){
		cout << x + y << endl;
	}
	else if(op == '-'){
		cout << x - y << endl;
	}
	else if(op == '*'){
		cout << x * y << endl;
	}
	else{
		exit(1);
	}

	if (os->bad()) {
		cerr << "cannot write to output stream."
		     << endl;
		exit(1);
	}
	if (is->bad()) {
		cerr << "cannot read from input stream."
		     << endl;
		exit(1);
	}
	if (!is->eof()) {
		cerr << "cannot find EOF on input stream."
		     << endl;
		exit(1);
	}
}




/***** Función main **********************************************************/
int main(int argc, char * const argv[]){

	cmdline cmdl(options);
	cmdl.parse(argc, argv);
	process_input(iss, oss);


=======
>>>>>>> 8694f4d3ee898246221374ca720739d387abc592
	return 0;
}
