CC=g++
CFLAGS=-c -Wall -O2 -std=gnu++11

all: MiningUsingFPTree


MiningUsingFPTree.o: MiningUsingFPTree.cpp
	$(CC) $(CFLAGS) MiningUsingFPTree.cpp


MiningUsingFPTree: MiningUsingFPTree.o ../lib/BangBit.o ../lib/FPTree.o ../lib/MiningAbstractClass.o ../lib/Sorting_Support.o ../lib/FPTree_Support.o
	$(CC) MiningUsingFPTree.o ../lib/BangBit.o ../lib/FPTree.o ../lib/MiningAbstractClass.o ../lib/Sorting_Support.o ../lib/FPTree_Support.o -o MiningUsingFPTree
	


clean:
	rm -rf *.o
	rm -f MiningUsingFPTree
	rm -f result.txt

