#Makefile for Dynamic and Memoized
#Esther Adu
#COP4531
#22 March 2017

all: Dynamic.x Memoized.x

Dynamic.x: Dynamic.o
	g++ -o Dynamic.x Dynamic.o
Dynamic.o: Dynamic.cpp
	g++ -c Dynamic.cpp
Memoized.x: Memoized.o
	g++ -o Memoized.x Memoized.o
Memoized.o: Memoized.cpp
	g++ -c Memoized.cpp

clean:
	rm *.o *.x
