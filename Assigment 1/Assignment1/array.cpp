#include "array.h"
#include <iostream>

using namespace std;

//Default constructor with constant capacity of 10
Array::Array() {
	int myArbitaryArray = 10;
	myArray = new ItemType[myArbitaryArray];
	capacity = myArbitaryArray;
	SIZE = 0;
}

//Default constructor with a parameter
Array::Array(int Size) {
	int mySize = Size;
	myArray = new ItemType[mySize];
	capacity = mySize;
	SIZE = 0;
}

//Erases the object of Array 
// returns the heap memory
Array::~Array() {
	delete[] myArray;
}

void Array::add(int item, int place) {
	myArray[place] = item;
}

int Array::size() const {
	return SIZE;
}

int Array::myItem(int place) {
	return myArray[place];
}