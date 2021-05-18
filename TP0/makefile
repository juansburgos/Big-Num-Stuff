CFLAGS=-g -pedantic -Wall
CC=g++

all: tp0 clear
all_test: tests clear test

#Make test
ifeq ($(OS),Windows_NT)
tests: tests.o bignum.o cmdline.o utils.o
	$(CC) $(CFLAGS) -o run_test.exe tests.o bignum.o cmdline.o utils.o
else
tests: tests.o bignum.o cmdline.o utils.o
	$(CC) $(CFLAGS) -o run_test tests.o bignum.o cmdline.o utils.o

endif

#Make Main
ifeq ($(OS),Windows_NT)
tp0: main.o bignum.o cmdline.o utils.o
	$(CC) $(CFLAGS) -o tp0.exe main.o bignum.o cmdline.o utils.o
else
tp0: main.o bignum.o cmdline.o utils.o
	$(CC) $(CFLAGS) -o tp0 main.o bignum.o cmdline.o utils.o
endif

#Make Obj
tests.o: tests.cpp cmdline.h bignum.h utils.h
	$(CC) $(CFLAGS) -o tests.o  -c tests.cpp

main.o: main.cpp cmdline.h bignum.h utils.h
	$(CC) $(CFLAGS) -o main.o  -c main.cpp

utils.o: utils.cpp  utils.h
	$(CC) $(CFLAGS) -o utils.o  -c utils.cpp

bignum.o: bignum.cpp  bignum.h utils.h
	$(CC) $(CFLAGS) -o bignum.o -c bignum.cpp

cmdline.o: cmdline.cpp cmdline.h
	$(CC) $(CFLAGS) -o cmdline.o  -c cmdline.cpp

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
	copy tp0 ../tp0
else
install:
	cp tp0 ../tp0
endif
