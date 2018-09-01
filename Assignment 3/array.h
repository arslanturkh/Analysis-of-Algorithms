#pragma once

#ifndef ARRAY
#define ARRAY

#include "cities.h"
#include <iostream>

using namespace std;
typedef City ItemType;

class Array {

public:
	Array();

	Array(int mySize);

	~Array();

	void insert(const ItemType& item, int place);

	int size() const;

	ItemType retrieve(int place);

	void swap(int place1, int place2);

private:
	ItemType* myArray;
	ItemType temporary;
	int capacity;
	int SIZE;

};
#endif // !ARRAY