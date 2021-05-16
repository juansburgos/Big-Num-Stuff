CFLAGS=-g -pedantic -Werror -Wall 
CC=g++

all: tp0 clear

tp0: main.o bignum.o cmdline.o bool.o
	$(CC) $(CFLAGS) -o tp0 main.o bignum.o cmdline.o bool.o

main.o: main.cpp cmdline.h bignum.h bool.h 
	$(CC) $(CFLAGS) -o main.o  -c main.cpp 

bool.o: bool.cpp  bool.h
	$(CC) $(CFLAGS) -o bool.o  -c bool.cpp 

bignum.o: bignum.cpp  bignum.h bool.h
	$(CC) $(CFLAGS) -o bignum.o -c bignum.cpp 

cmdline.o: cmdline.cpp cmdline.h
	$(CC) $(CFLAGS) -o cmdline.o  -c cmdline.cpp 

clear:
	rm *.o

install:
	cp tp0 ../tp0
