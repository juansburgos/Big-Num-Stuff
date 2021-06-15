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

	/*string expresion("	(-1 ) * 5	+	1 + (3	)");
	cout << "Antes:" << expresion << endl;
	cout << "Despues:" << remove_spaces(expresion, " \f\r\t\v") << endl;*/

	/*Stack<Token>* stk = process_line(expresion);
	stk->print();
	bignum ans = evalPostfix(stk);

	cout << "ans: " << ans << endl;*/
	if (process_input(iss, oss, precision) == false){
		return 1;
	}
	
	return 0;
}
