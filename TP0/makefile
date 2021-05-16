CFLAGS=-pedantic -Wall 
CC=g++

all: tp0 clear

tp0: main.o bignum.o bool.o cmdline.o 
	$(CC) $(CFLAGS) -o main.o bignum.o bool.o cmdline.o 

main.o: main.cc cmdline.h bignum.h bool.h 
	$(CC) $(CFLAGS) -o main.o -c main.cc

bool.o: bool.cc  bool.h
	$(CC) $(CFLAGS) -o bool.o -c bool.cc

bignum.o: bignum.cc  bignum.h
	$(CC) $(CFLAGS) -o bignum.o -c bignum.cc

cmdline.o: cmdline.cc  cmdline.h
	$(CC) $(CFLAGS) -o cmdline.o -c cmdline.cc

clear:
	rm *.o

install:
	cp tp0 ../tp0
