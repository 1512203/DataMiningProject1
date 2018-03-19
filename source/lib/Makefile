CC=g++
CFLAGS=-c -Wall -O2

all: BitMap.o


BitMap.o: BitMap.cpp BitMap.h
	$(CC) $(CFLAGS) BitMap.cpp BitMap.h

clean:
	rm -rf *.o
	rm -rf *.h.gch
