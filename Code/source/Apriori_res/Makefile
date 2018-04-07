CC=g++
CFLAGS=-c -Wall -O2 -std=gnu++11

all: MiningUsingApriori 


MiningUsingApriori.o: MiningUsingApriori.cpp
	$(CC) $(CFLAGS) MiningUsingApriori.cpp


MiningUsingApriori: MiningUsingApriori.o ../lib/BangBit.o ../lib/Apriori.o ../lib/MiningAbstractClass.o 
	$(CC) MiningUsingApriori.o ../lib/BangBit.o ../lib/Apriori.o ../lib/MiningAbstractClass.o -o MiningUsingApriori


clean:
	rm -rf *.o
	rm -f MiningUsingApriori
	rm -f result.txt

