#include "array.h"
#include <iostream>
#include"cities.h"

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

void Array::insert(const ItemType& item, int place) {
	myArray[place] = item;
}

int Array::size() const {
	return SIZE;
}

ItemType Array::retrieve(int place) {
	return myArray[place];
}

void Array::swap(int place1, int place2) {
	temporary = myArray[place1];
	myArray[place1] = myArray[place2];
	myArray[place2] = temporary;
}