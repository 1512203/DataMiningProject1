CC=g++
CFLAGS=-c -Wall -O2 -std=gnu++11

all: MiningUsingApriori MiningUsingFPTree


test_MiningUsingFPTree.o: test_MiningUsingFPTree.cpp
	$(CC) $(CFLAGS) test_MiningUsingFPTree.cpp


MiningUsingFPTree: test_MiningUsingFPTree.o ../lib/BangBit.o ../lib/FPTree.o ../lib/MiningAbstractClass.o ../lib/Sorting_Support.o ../lib/FPTree_Support.o
	$(CC) test_MiningUsingFPTree.o ../lib/BangBit.o ../lib/FPTree.o ../lib/MiningAbstractClass.o ../lib/Sorting_Support.o ../lib/FPTree_Support.o -o MiningUsingFPTree
	

test_MiningUsingApriori.o: test_MiningUsingApriori.cpp
	$(CC) $(CFLAGS) test_MiningUsingApriori.cpp


MiningUsingApriori: test_MiningUsingApriori.o ../lib/BangBit.o ../lib/Apriori.o ../lib/MiningAbstractClass.o 
	$(CC) test_MiningUsingApriori.o ../lib/BangBit.o ../lib/Apriori.o ../lib/MiningAbstractClass.o -o MiningUsingApriori


clean:
	rm -rf *.o
	rm -f MiningUsingApriori
	rm -f MiningUsingFPTree
	rm -f result.txt

