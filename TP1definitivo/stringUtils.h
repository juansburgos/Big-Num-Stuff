/*Este archivo contiene prototipos de funciones para la manipulacion
de strings*/

#ifndef STRING_UTILS__H
#define STRING_UTILS__H

#include <algorithm>
#include <string>
#include "Stack.h"

enum OP { OP_SUMA=0, OP_RESTA, OP_MULT, OP_DIV, OP_LP, OP_RP };
enum SIMB { SIMB_e=0, SIMB_E=1};

static string WHITESPACES = " \f\r\t\v";

						/*PROTOTIPOS*/
Stack<string> * read_math_expression(const string &input);
string pop_extension(const string& s);
string pop_n(string ss, int n);
string get_files_name(const string& name, const char extract, const string& extension);
int remplace_1(string& my_str, const string& sub_str, const char c);
bool containChar(const string & input, char c);
bool isBalanced(string expr);

string fullTrim(string str);
string remove_spaces(string s, string cads);

#endif
