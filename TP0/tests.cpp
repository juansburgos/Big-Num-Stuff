#include "tests.h"

//Printea separador
void ps(){
    cout << "================================================" << endl;
}

//Printeo bievenida
void wellcome(){
  ps();
  cout << "TESTING..." << endl;
  ps();
}

void test_score(){
  cout << "Test: " << ok_tests << "/" << total_test << endl;
}

void print_results(){
  cout << "<ALL TESTS>" << endl;
  test_score();
}

//Estructura de un TEST
void TEST(bool (*f)()){

  cout << "<Test " << ok_tests <<">" << endl;

  total_test++;
  if(f() == true)
    ok_tests++;

  test_score();
  ps();
}

//Creo un test para probar asignacion =
bool test_equal_operator1(){
  const string a = "-145";
  const string b = "323";
  Bignum x(a),y(b),z;

  z = x;
  cout << "z == x" << endl;
  return z == x; //Si no se utiliza assert, utilizar error=False.
}

//Creo un test para probar multiple asignacion = =
bool test_equal_operator2(){
  const string a = "-145";
  const string b = "323";
  Bignum x(a),y(b),z;

  z = x = y;
  cout << "x == y" << endl;
  cout << "z == x" << endl;
  cout << "x == y" << endl;
  return (z == x) & (z == y); //Si no se utiliza assert, utilizar error=False.
}

//Test 1 para probar operadores + y -
bool test_plus_minus_operators1(){
  const string a = "-145";
  const string b = "323";
  const string res = "178";
  Bignum x(a),y(b),r(res),z;

  z = x + y;

  cout << "z = x + y" << endl;
  return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 2 para probar operadores + y -
bool test_plus_minus_operators2(){
  const string a = "-145";
  const string b = "323";
  const string res = "178";
  Bignum x(a),y(b),r(res),z;

  z = y + x;

  cout << "z = y + x" << endl;
  return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 3 para probar operadores + y -
bool test_plus_minus_operators3(){
  const string a = "-145";
  const string b = "323";
  const string res = "-468";
  Bignum x(a),y(b),r(res),z;

  z = x - y;

  cout << "z = x - y" << endl;
  return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 4 para probar operadores + y -
bool test_plus_minus_operators4(){
  const string a = "-145";
  const string b = "323";
  const string res = "468";
  Bignum x(a),y(b),r(res),z;

  z = y - x;

  cout << "z = y - x" << endl;
  return (z == r); //Si no se utiliza assert, utilizar error=False.
}

int main(int argc, char const *argv[]){
  /*
    COMPILACION: make all_test

    INFO:
    Acá se va agregar todos los test que necesitemos probar.
    La idea es que queden para siempre cosa que cuando avancemos en el proyecto
    si tenemos algún bug lo podamos detectar fácil.
    ok_test: Mide la cantidad de test que no fallaron.
    total_test: Cuando se agrega más test, éste número incrementa sólo.
  */
  wellcome();

  TEST(test_equal_operator1);
  TEST(test_equal_operator2);
  TEST(test_plus_minus_operators1);
  TEST(test_plus_minus_operators2);
  TEST(test_plus_minus_operators3);
  TEST(test_plus_minus_operators4);

  print_results();
}
