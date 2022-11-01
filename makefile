main: main.o matrix.o 
	g++ main.o matrix.o -o main
	./main

matrix.o: implementation/matrix.cpp headers/matrix.h
	g++ -c implementation/matrix.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o main