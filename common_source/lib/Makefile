CC=g++
CFLAGS=-c -Wall -O2

all: BangBit.o CSDLNhiPhan.o
	

BangBit.o: BangBit.cpp BangBit.h
	$(CC) $(CFLAGS) BangBit.cpp

CSDLNhiPhan.o: CSDLNhiPhan.cpp CSDLNhiPhan.h BangBit.cpp BangBit.h
	$(CC) $(CFLAGS) CSDLNhiPhan.cpp BangBit.cpp 

clean:
	rm -rf *.o
	rm -rf *.h.gch
