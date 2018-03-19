CC=g++
CFLAGS=-c -Wall -O2

all: test


test.o: test.cpp 
	$(CC) $(CFLAGS) test.cpp 

test: test.o ../lib/BitMap.o
	$(CC) test.o ../lib/BitMap.o -o test

clean:
	rm -rf *.o
	rm test
