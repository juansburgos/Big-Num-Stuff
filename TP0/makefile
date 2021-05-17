CFLAGS=-g -pedantic -Werror -Wall 
CC=g++

all: tp0 clear

ifeq ($(OS),Windows_NT)
tp0: main.o bignum.o cmdline.o bool.o
	$(CC) $(CFLAGS) -o tp0.exe main.o bignum.o cmdline.o bool.o
else
tp0: main.o bignum.o cmdline.o bool.o
	$(CC) $(CFLAGS) -o tp0 main.o bignum.o cmdline.o bool.o
endif


main.o: main.cpp cmdline.h bignum.h bool.h 
	$(CC) $(CFLAGS) -o main.o  -c main.cpp 

bool.o: bool.cpp  bool.h
	$(CC) $(CFLAGS) -o bool.o  -c bool.cpp 

bignum.o: bignum.cpp  bignum.h bool.h
	$(CC) $(CFLAGS) -o bignum.o -c bignum.cpp 

cmdline.o: cmdline.cpp cmdline.h
	$(CC) $(CFLAGS) -o cmdline.o  -c cmdline.cpp 

ifeq ($(OS),Windows_NT)
clear:
	del *.o
else
clear:
	rm *.o
endif

ifeq ($(OS),Windows_NT)
install:
	copy tp0 ../tp0
else
install:
	cp tp0 ../tp0
endif
