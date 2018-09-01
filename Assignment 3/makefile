040100174: main.o array.o cities.o
	g++ main.o  array.o  cities.o  -o 040100174
	
main.o: main.cpp
	g++ -c -std=c++11 main.cpp
	
array.o: array.cpp array.h
	g++ -c -std=c++11 array.cpp
	
cities.o: cities.cpp cities.h
	g++ -c -std=c++11 cities.cpp
	
clean: 
	rm *.o 040100174
