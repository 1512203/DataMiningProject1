CC=g++
CFLAGS=-c -Wall -O2 -std=gnu++11

all: test
	

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp 

test: test.o ../lib/BangBit.o ../lib/CSDLNhiPhan.o
	$(CC) test.o ../lib/BangBit.o ../lib/CSDLNhiPhan.o -o test

clean:
	rm -rf *.o
	rm -f test
	rm -f result.txt

