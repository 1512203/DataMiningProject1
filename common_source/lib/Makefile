CC=g++
CFLAGS=-c -Wall -O2 -std=gnu++11

all: BangBit.o MiningAbstractClass.o Apriori.o FPTree_Support.o FPTree.o Sorting_Support.o
	

BangBit.o: BangBit.cpp BangBit.h
	$(CC) $(CFLAGS) BangBit.cpp

Apriori.o: Apriori.cpp Apriori.h MiningAbstractClass.o
	$(CC) $(CFLAGS) Apriori.cpp 

FPTree.o: FPTree.cpp FPTree.h
	$(CC) $(CFLAGS) FPTree.cpp

Sorting_Support.o: Sorting_Support.cpp Sorting_Support.h
	$(CC) $(CFLAGS) Sorting_Support.cpp

FPTree_Support.o: FPTree_Support.cpp FPTree_Support.h 
	$(CC) $(CFLAGS) FPTree_Support.cpp

MiningAbstractClass.o: MiningAbstractClass.cpp MiningAbstractClass.h BangBit.o
	$(CC) $(CFLAGS) MiningAbstractClass.cpp

clean:
	rm -rf *.o
	rm -rf *.h.gch
