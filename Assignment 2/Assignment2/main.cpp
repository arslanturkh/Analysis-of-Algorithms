#include "array.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <cassert>
#include <time.h>

using namespace std;
//read data.txt
void readFile(ifstream& f, int size, Array& myArrayAdress);
//open data.txt
void openFile(ifstream& f, string fileName);
//write sorted.txt file
void printFile(Array& myArrayAdress, int size);
//randomized quick sort
int randomizedPartition(Array& myArrayAdress, int low, int high);
void randomizedQuickSort(Array& myArrayAdress, int low, int high);
//insertion sort
void insertionSort(Array& myArrayAdress, int size);
//merge sort
void mergeSort(Array& myArrayAdress, int low, int high);
void merge(Array& myArrayAdress, int low, int mid, int high);



int main(int argc, char **argv) {
	cout << "main function is working..." << endl;
	string arraySize = argv[1];
	int sizeOfArray = atoi(arraySize.c_str());

	string fileName = "data.txt";
	ifstream f;
	Array myArray(sizeOfArray);


	openFile(f, fileName);
	readFile(f, sizeOfArray, myArray);

	clock_t tstart = clock();

	cout << "Randomized Quick Sort is working..." << endl;
	randomizedQuickSort(myArray, 0, sizeOfArray - 1);
	cout << "Randomized Quick Sort is done." << endl;
	printf("Randomized Quick Sort took %f seconds\n", (double)(clock() - tstart) / CLOCKS_PER_SEC);
	printFile(myArray, sizeOfArray);

	cout << "main function is done." << endl;
}



void openFile(ifstream& f, string fileName) {
	cout << "openFile function is working..." << endl;
	f.open(fileName);
	assert(f.is_open());
	cout << "openFile function is done." << endl;
}

void readFile(ifstream& f, int size, Array& myArrayAdress) {
	cout << "readFile function is working..." << endl;
	string line;
	int value, i;

	for (i = 0; i < size; i++) {
		getline(f, line);
		value = atoi(line.c_str());
		myArrayAdress.add(value, i);
	}
	cout << "readFile function is done." << endl;
}

void printFile(Array& myArrayAdress, int size) {
	cout << "printFile function is working..." << endl;
	ofstream outFile("sorted.txt");

	for (int i = 0; i < size; i++) {
		outFile << myArrayAdress.myItem(i) << endl;
	}
	cout << "printFile function is done." << endl;
}

int randomizedPartition(Array& myArrayAdress, int low, int high) {
	int lowIndex = low - 1, i;
	int temp = 0;
	int randomNumber = (rand() % (high - low)) + low;

	temp = myArrayAdress.myItem(randomNumber);
	myArrayAdress.add(myArrayAdress.myItem(high), randomNumber);
	myArrayAdress.add(temp, high);

	for (i = low; i < high; i++) {
		if (myArrayAdress.myItem(i) <= myArrayAdress.myItem(high)) {
			lowIndex++;
			temp = myArrayAdress.myItem(lowIndex);
			myArrayAdress.add(myArrayAdress.myItem(i), lowIndex);
			myArrayAdress.add(temp, i);
		}
	}

	lowIndex++;
	temp = myArrayAdress.myItem(lowIndex);
	myArrayAdress.add(myArrayAdress.myItem(high), lowIndex);
	myArrayAdress.add(temp, high);

	return lowIndex;
}

void randomizedQuickSort(Array& myArrayAdress, int low, int high) {
	if (low < high) {
		int q = randomizedPartition(myArrayAdress, low, high);

		randomizedQuickSort(myArrayAdress, low, q - 1);
		randomizedQuickSort(myArrayAdress, q + 1, high);
	}
}