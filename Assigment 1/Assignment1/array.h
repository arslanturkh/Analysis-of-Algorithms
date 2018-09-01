#pragma once

#ifndef ARRAY
#define ARRAY

#include <iostream>
using namespace std;

typedef int ItemType;

class Array {

public:
	Array();

	Array(int mySize);

	~Array();

	void add(int item, int place);

	int size() const;

	int myItem(int place);

private:
	ItemType* myArray;
	int capacity;
	int SIZE;

};
#endif // !ARRAY


