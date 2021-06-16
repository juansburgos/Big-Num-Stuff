CFLAGS=-g -pedantic -Wall
CC=g++

all: tp1 clear
all_test: tests clear test

#Make test
ifeq ($(OS),Windows_NT)
tests: tests.o bignum.o cmdline.o utils.o process.o functions.o line_utils.o stringUtils.o Token.o testprototypes.o
	$(CC) $(CFLAGS) -o run_test.exe tests.o bignum.o cmdline.o utils.o process.o functions.o line_utils.o stringUtils.o Token.o testprototypes.o
else
tests: tests.o bignum.o cmdline.o utils.o process.o testprototypes.o
	$(CC) $(CFLAGS) -o run_test tests.o bignum.o cmdline.o utils.o process.o testprototypes.o

endif

#Make Main
ifeq ($(OS),Windows_NT)
tp0: main.o bignum.o cmdline.o utils.o process.o functions.o line_utils.o stringUtils.o Token.o producto.o
	$(CC) $(CFLAGS) -o tp1.exe main.o bignum.o cmdline.o utils.o process.o functions.o line_utils.o stringUtils.o Token.o producto.o
else
tp1: main.o bignum.o cmdline.o utils.o process.o functions.o line_utils.o stringUtils.o Token.o producto.o
	$(CC) $(CFLAGS) -o tp1 main.o bignum.o cmdline.o utils.o process.o functions.o line_utils.o stringUtils.o Token.o producto.o
endif

#Make Obj
tests.o: tests.cpp cmdline.h bignum.h utils.h
	$(CC) $(CFLAGS) -o tests.o  -c tests.cpp

producto.o: producto.cpp producto.h bignum.h
	$(CC) $(CFLAGS) -o producto.o  -c producto.cpp

testprototypes.o: testprototypes.cpp tests.h
	$(CC) $(CFLAGS) -o testprototypes.o  -c testprototypes.cpp

main.o: main.cpp main.h cmdline.h bignum.h utils.h
	$(CC) $(CFLAGS) -o main.o  -c main.cpp

utils.o: utils.cpp  utils.h
	$(CC) $(CFLAGS) -o utils.o  -c utils.cpp

bignum.o: bignum.cpp  bignum.h utils.h
	$(CC) $(CFLAGS) -o bignum.o -c bignum.cpp

cmdline.o: cmdline.cpp cmdline.h
	$(CC) $(CFLAGS) -o cmdline.o  -c cmdline.cpp

process.o: process.cpp process.h
	$(CC) $(CFLAGS) -o process.o  -c process.cpp

#TP1 Obj
functions.o: functions.cpp functions.h tokenDictionary.h
	$(CC) $(CFLAGS) -o functions.o  -c functions.cpp

line_utils.o: line_utils.cpp line_utils.h tokenDictionary.h
	$(CC) $(CFLAGS) -o line_utils.o  -c line_utils.cpp

stringUtils.o: stringUtils.cpp stringUtils.h tokenDictionary.h
	$(CC) $(CFLAGS) -o stringUtils.o  -c stringUtils.cpp

Token.o: Token.cpp Token.h tokenDictionary.h
	$(CC) $(CFLAGS) -o Token.o  -c Token.cpp

#Make Clear
ifeq ($(OS),Windows_NT)
clear:
	del *.o
else
clear:
	rm *.o
endif

#Make Test
ifeq ($(OS),Windows_NT)
test:
	run_test.exe
else
test:
	./run_test
endif

ifeq ($(OS),Windows_NT)
install:
	copy tp1 ../tp1
else
install:
	cp tp1 ../tp1
endif

leak_test:
	valgrind --leak-check=full ./run_test
