
/********************************************************************************************


		OPERADORES BIGNUM


 ********************************************************************************************/

bignum bignum::standard(const bignum&b1, const bignum&b2){
	if(b1.size == 0 || b2.size == 0){
		bignum zero("0");
		return zero;
	}

	bool signo;
	size_t tam (b1.size + b2.size);
	unsigned short carry = 0, *auxdig = new unsigned short [tam]{0};

	for(int i = b2.size-1; i >= 0; i--){
		carry = 0;
		for(int h = b1.size-1; h >= 0; h--){
			auxdig[i+h+1] += (carry + b2.digits[i] * b1.digits[h]);
			carry = auxdig[i+h+1] / 10;
			auxdig[i+h+1] = auxdig[i+h+1] % 10;
		}
		auxdig[i] = carry;
	}
	signo = !(b1.sign == b2.sign);

	bignum nuevo(signo, tam, auxdig);
	delete [] auxdig;
	return nuevo;
}



bignum bignum::karatsuba(const bignum&b1, const bignum&b2){
	if((b1.size == 1 && b1.digits[0] == 0) || (b2.size == 1 && b2.digits[0] == 0)) {
		bignum zero("0");
		return zero;
	}

	bool signo;
	signo = !(b1.sign == b2.sign);

	if(b1.size == 1 && b2.size == 1) {
		unsigned short *aux_nuevo = new unsigned short [2]{0};
		aux_nuevo[0] = (b1.digits[0] * b2.digits[0])/10;
		aux_nuevo[1] = (b1.digits[0] * b2.digits[0])%10;
		bignum nuevo(signo, 2, aux_nuevo);
		return nuevo;
	}

	// Busco el exponente como el tamaño más grande dividido 2
	size_t m;
	if(b1.size >= b2.size) {
		m = b1.size / 2;
		if(b1.size % 2) {
			m++;
		}
	}
	else {
		m = b2.size/2;
		if(b2.size % 2) {
			m++;
		}
	}

	// Parto los números
	unsigned short *auxb1_1 = new unsigned short [m]{0};
	unsigned short *auxb1_0 = new unsigned short [m]{0};
	unsigned short *auxb2_1 = new unsigned short [m]{0};
	unsigned short *auxb2_0 = new unsigned short [m]{0};

	// Creo los fragmentos para hacer las operaciones
	for(size_t i=0; i < m; i++){
		auxb1_1[m-i-1] = (b1.size > m && b1.size-m-1 >= i) ? b1.digits[b1.size-m-i-1] : 0;
		auxb2_1[m-i-1] = (b2.size > m && b2.size-m-1 >= i) ? b2.digits[b2.size-m-i-1] : 0;
		auxb1_0[m-i-1] = (b1.size-1 >= i) ? b1.digits[b1.size-i-1] : 0;
		auxb2_0[m-i-1] = (b2.size-1 >= i) ? b2.digits[b2.size-i-1] : 0;
	}

	bignum b1_1(false, m, auxb1_1);
	bignum b2_1(false, m, auxb2_1);
	bignum b1_0(false, m, auxb1_0);
	bignum b2_0(false, m, auxb2_0);

	delete [] auxb1_0;
	delete [] auxb1_1;
	delete [] auxb2_0;
	delete [] auxb2_1;

	// Hago las operaciones parciales
	bignum z2, z1, z0;

	// Calculo z2
	z2 = b1_1*b2_1;
	unsigned short *auxz2_1 = new unsigned short [(2*m)+z2.size]{0};
	for(size_t i=0; i < z2.size; i++){
		if(i<z2.size) { // Tengo que poner el 0 del exponente
			auxz2_1[i] = z2.digits[i];
		}
	}
	z2 = bignum(false, (2*m)+z2.size, auxz2_1);
	delete [] auxz2_1;

	// Calculo z1
	z1 = b1_1*b2_0 + b1_0*b2_1;
	unsigned short *auxz1_1 = new unsigned short [m+z1.size]{0};
	for(size_t i=0; i < z1.size; i++){
		if(i<z1.size) { // Tengo que poner el 0 del exponente
			auxz1_1[i] = z1.digits[i];
		}
	}
	z1 = bignum(false, m+z1.size, auxz1_1);
	delete [] auxz1_1;

	// Calculo z0
	z0 = b1_0*b2_0;


	bignum nuevo(z2+z1+z0);
	nuevo.sign = signo;
	return nuevo;
}



bignum operator/(const bignum &b1, const bignum &b2){
	bignum zero("0"), _b2;
	if(b2.sign == true) {
		_b2 = zero-b2;
	}
	else {
		_b2 = b2;
	}

	if(b1 == zero){
		return zero;
	}
	if(b1.size < _b2.size){
		return zero;
	}
	if(b1.size == _b2.size && b1.digits[0] < _b2.digits[0]){
		return zero;
	}
	if(_b2 == zero){
		exit (2);
	}
	bool signo;
	signo = !(b1.sign == b2.sign);

	size_t tam = b1.size;
	unsigned short *auxdig = new unsigned short [tam]{0};

	bignum frag, tmp("1");
	bignum unidad("1");
	bignum decena("10");

	for(size_t i = 0; i < b1.size; i++){
		tmp.digits[0] = b1.digits[i];
		frag = (frag * decena) + tmp;
		// Si frag*decena es menor que b2, el multiplicador me daría 0
		if(frag < _b2){
			auxdig[i] = 0;
			continue;
		}
		// Si llegué hasta acá es porque el divisor es a lo sumo 9 veces más chico que el dividendo parcial
		// Busco el valor multiplicador (tiene que estar entre 1 y 9 por el if anterior)
		bignum n;
		for(n = unidad; frag-(n*_b2) >= _b2; n = n + unidad);
		// Cargo ese número como el i-esimo decimal de auxdig
		auxdig[i] = n.digits[0];
		// Actualizo el valor de frag
		frag = frag-(n*_b2);
	}
	
	bignum nuevo(signo, tam, auxdig);
	delete [] auxdig;
	return nuevo;
}




bool operator>=(const bignum& b1, const bignum& b2) {
	return ((b1 > b2) || (b1 == b2));
}




/********************************************************************************************


		TESTS


 ********************************************************************************************/


//Test 1 para probar el operador /
bool test_divition_operator1() {
	const string a = "155";
	const string b = "5";
	const string res = "31";
	bignum x(a), y(b), r(res), z;

	z = x / y;

	cout << "z = " << x << " / " << y << " = " << z << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 2 para probar el operador /
bool test_divition_operator2() {
	const string a = "155";
	const string b = "-5";
	const string res = "-31";
	bignum x(a), y(b), r(res), z;

	z = x / y;

	cout << "z = " << x << " / " << y << " = " << z << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 3 para probar el operador /
bool test_divition_operator3() {
	const string a = "-5689746";
	const string b = "46598";
	const string res = "-122";
	bignum x(a), y(b), r(res), z;

	z = x / y;

	cout << "z = " << x << " / " << y << " = " << z << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 4 para probar el operador /
bool test_divition_operator4() {
	const string a = "-35775";
	const string b = "568";
	const string res = "-62";
	bignum x(a), y(b), r(res), z;

	z = x / y;

	cout << "z = " << x << " / " << y << " = " << z << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 5 para probar el operador /
bool test_divition_operator5() {
	const string a = "-35775";
	const string b = "56008";
	const string res = "0";
	bignum x(a), y(b), r(res), z;

	z = x / y;

	cout << "z = " << x << " / " << y << " = " << z << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 6 para probar el operador /
bool test_divition_operator6() {
	const string a = "0";
	const string b = "56008";
	const string res = "0";
	bignum x(a), y(b), r(res), z;

	z = x / y;

	cout << "z = " << x << " / " << y << " = " << z << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 7 para probar el operador /
bool test_divition_operator7() {
	const string a = "345353";
	const string b = "0";
	bignum x(a), y(b), r, z;

	z = x / y;

	cout << "z = " << x << " / " << y << " = " << z << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 8 para probar el operador /
bool test_divition_operator8() {
	const string a = "100000";
	const string b = "10";
	const string res = "10000";
	bignum x(a), y(b), r(res), z;

	z = x / y;

	cout << "z = " << x << " / " << y << " = " << z << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 1 para probar Karatsuba
bool test_karatsuba1() {
	const string a = "123";
	const string b = "456";
	bignum x(a), y(b);
	bignum r, z;

	r = r.standard(x,y);
	z = z.karatsuba(x,y);

	cout << "Standard:  " << x << " * " << y << " = " << r << endl;
	cout << "Karatsuba: " << x << " * " << y << " = " << z << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 2 para probar Karatsuba
bool test_karatsuba2() {
	const string a = "3";
	const string b = "5";
	bignum x(a), y(b);
	bignum r, z;

	r = r.standard(x,y);
	z = z.karatsuba(x,y);

	cout << "Standard:  " << x << " * " << y << " = " << r << endl;
	cout << "Karatsuba: " << x << " * " << y << " = " << z << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 3 para probar Karatsuba
bool test_karatsuba3() {
	const string a = "425";
	const string b = "111";
	bignum x(a), y(b);
	bignum r, z;

	r = r.standard(x,y);
	z = z.karatsuba(x,y);

	cout << "Standard:  " << x << " * " << y << " = " << r << endl;
	cout << "Karatsuba: " << x << " * " << y << " = " << z << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 4 para probar Karatsuba
bool test_karatsuba4() {
	const string a = "2453";
	const string b = "123143456";
	bignum x(a), y(b);
	bignum r, z;

	r = r.standard(x,y);
	z = z.karatsuba(x,y);

	cout << "Standard:  " << x << " * " << y << " = " << r << endl;
	cout << "Karatsuba: " << x << " * " << y << " = " << z << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}

//Test 5 para probar Karatsuba
bool test_karatsuba5() {
	const string a = "0";
	const string b = "123143456";
	bignum x(a), y(b);
	bignum r, z;

	r = r.standard(x,y);
	z = z.karatsuba(x,y);

	cout << "Standard:  " << x << " * " << y << " = " << r << endl;
	cout << "Karatsuba: " << x << " * " << y << " = " << z << endl;
	return (z == r); //Si no se utiliza assert, utilizar error=False.
}