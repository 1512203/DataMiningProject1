CC=g++
CFLAGS=-c -Wall -O2 -std=gnu++11

all: BangBit.o MiningAbstractClass.o Apriori.o FPTree_Support.o FPTree.o Sorting_Support.o
	

BangBit.o: BangBit/BangBit.cpp BangBit/BangBit.h
	$(CC) $(CFLAGS) BangBit/BangBit.cpp

Apriori.o: Apriori/Apriori.cpp Apriori/Apriori.h MiningAbstractClass.o
	$(CC) $(CFLAGS) Apriori/Apriori.cpp 

FPTree.o: FPTree/FPTree.cpp FPTree/FPTree.h MiningAbstractClass.o FPTree_Support.o
	$(CC) $(CFLAGS) FPTree/FPTree.cpp

Sorting_Support.o: FPTree/Sorting_Support.cpp FPTree/Sorting_Support.h
	$(CC) $(CFLAGS) FPTree/Sorting_Support.cpp

FPTree_Support.o: FPTree/FPTree_Support.cpp FPTree/FPTree_Support.h Sorting_Support.o
	$(CC) $(CFLAGS) FPTree/FPTree_Support.cpp

MiningAbstractClass.o: MiningAbstractClass.cpp MiningAbstractClass.h BangBit.o
	$(CC) $(CFLAGS) MiningAbstractClass.cpp

clean:
	rm -rf *.o
	rm -rf *.h.gch
