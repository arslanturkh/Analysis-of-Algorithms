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
//insertion sort
void insertionSort(Array& myArrayAdress, int size);
//merge sort
void mergeSort(Array& myArrayAdress, int low, int high);
void merge(Array& myArrayAdress, int low, int mid, int high);



int main(int argc, char **argv) {
	cout << "main function is working..." << endl;
	string arraySize = argv[1];
	int sizeOfArray = atoi(arraySize.c_str());
	string choice = argv[2];
	string fileName = "data.txt";
	ifstream f;
	Array myArray(sizeOfArray);


	openFile(f, fileName);
	readFile(f, sizeOfArray, myArray);

	clock_t tstart = clock();

	if (choice.compare("InsertionSort") == 0) {
		insertionSort(myArray, sizeOfArray);
		printf("Insertion Sort took %f seconds\n", (double)(clock() - tstart) / CLOCKS_PER_SEC);
		printFile(myArray, sizeOfArray);
	}
	else if (choice.compare("MergeSort") == 0) {
		cout << "merge function is working..." << endl;
		mergeSort(myArray, 0, sizeOfArray - 1);
		cout << "merge function is done." << endl;
		printf("Merge Sort took %f seconds\n", (double)(clock() - tstart) / CLOCKS_PER_SEC);
		printFile(myArray, sizeOfArray);
	}
	else {
		cout << "You did wrong sorting choice!" << endl;
	}
	
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

void insertionSort(Array& myArrayAdress, int size) {
	cout << "insertionSort function is working..." << endl;
	int j, temp;

	for (int i = 0; i < size; i++) {
		j = i;

		while (j > 0 && myArrayAdress.myItem(j) < myArrayAdress.myItem(j - 1)) {
			temp = myArrayAdress.myItem(j);
			myArrayAdress.add(myArrayAdress.myItem(j - 1), j);
			myArrayAdress.add(temp, j - 1);
			j--;
		}
	}
	cout << "insertionSort function is done." << endl;
}

void mergeSort(Array& myArrayAdress, int low, int high) {
	//cout << "mergeSort function is working..." << endl;
	int mid;
	
	if (low < high) {
		mid = (low + high) / 2;
		mergeSort(myArrayAdress, low, mid);
		mergeSort(myArrayAdress, mid + 1, high);
		merge(myArrayAdress, low, mid, high);
	}
	//cout << "mergeSort function is done." << endl;
}

void merge(Array& myArrayAdress, int low, int mid, int high) {
	//cout << "merge function is working..." << endl;
	int counter1, counter2, counter3;
	Array myTempArray(high + 1);

	counter1 = low;
	counter2 = low;
	counter3 = mid + 1;

	while (counter1 <= mid && counter3 <= high) {
		if (myArrayAdress.myItem(counter1) < myArrayAdress.myItem(counter3)) {
			myTempArray.add(myArrayAdress.myItem(counter1), counter2);
			counter2++;
			counter1++;
		}
		else {
			myTempArray.add(myArrayAdress.myItem(counter3), counter2);
			counter2++;
			counter3++;
		}
	}

	while (counter1 <= mid) {
		myTempArray.add(myArrayAdress.myItem(counter1), counter2);
		counter2++;
		counter1++;
	}

	while (counter3 <= high) {
		myTempArray.add(myArrayAdress.myItem(counter3), counter2);
		counter2++;
		counter3++;
	}

	for (counter1 = low; counter1 < counter2; counter1++) {
		myArrayAdress.add(myTempArray.myItem(counter1), counter1);
	}

	//myTempArray.~Array();

	//cout << "merge function is done." << endl;
}
