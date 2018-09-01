#include <iostream>
#include <fstream>
#include <string>
#include <math.h>  
#include <stdlib.h> 
#include <cstdlib>
#include <time.h>
#include "array.h"
#include "cities.h"

using namespace std;
const float PI = 3.1415927;

float toRad(float degree);
float calculateDistance(float lat1, float long1, float lat2, float long2);
void heapify(Array& myArrayAdress, int max, int low);
void heapSort(Array& myArrayAdress, int size);
void printFile(Array& myArrayAdress, int size);

int main(int argc, char **argv) {
	cout << "main function is working..." << endl;
	string line,init;
	ifstream myfile("location.txt");
	int numberOfLocations,lineCounter = 0, numberOfClosestLocations;
	
	float initLatitude, initLongitude, distance;
	
	init = argv[1];
	numberOfLocations = atoi(init.c_str());
	Array myArray(numberOfLocations);
	init = argv[2];
	numberOfClosestLocations = atoi(init.c_str());
	init = argv[3];
	initLatitude = atof(init.c_str());
	init = argv[1];
	initLongitude = atof(init.c_str());
	
	if (myfile.is_open())
	{
		while ((getline(myfile, line)) && lineCounter < numberOfLocations)
		{
			unsigned pos = line.find("\t");
			string city = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find("\t");
			float latitude = atof(line.substr(0, pos).c_str());
			line = line.substr(pos + 1);
			float longitude = atof(line.substr(0, pos).c_str());
			//cout << city << " " << latitude << " " << longitude << endl;

			distance = calculateDistance(initLatitude, initLongitude, latitude, longitude);
			City *cities = new City(city, latitude, longitude, distance);
			myArray.insert(*cities,lineCounter);
			
			//cout << myArray.retrieve(lineCounter).getCity() << myArray.retrieve(lineCounter).getLatitude()
			//	<< " "<<myArray.retrieve(lineCounter).getLongitude()<< " " <<myArray.retrieve(lineCounter).getDistance()<< endl;
			
			lineCounter++;
		}
		myfile.close();
	}
	else
		cout << "File could not be opened." << endl;

	clock_t tstart = clock();
	cout << "Heap Sort is working..." << endl;
	heapSort(myArray, numberOfLocations);
	cout << "Heap Sort is done." << endl;
	printFile(myArray, numberOfClosestLocations);
	printf("Heap Sort and print took %f seconds\n", (double)(clock() - tstart) / CLOCKS_PER_SEC);
	
	cout << "main function is done." << endl;
	return 0;
}

float toRad(float degree) {
	return (degree / 180) * PI;
}

float calculateDistance(float lat1, float long1, float lat2, float long2) {
	float dlat, dlong, a, c;

	dlong = toRad(long1 - long2);
	dlat = toRad(lat1 - lat2);
	a = pow(sinf(dlat / 2), 2.0) + ((cosf(toRad(lat1)))*(cosf(toRad(lat2)))*(powf(sinf(dlong / 2), 2)));
	c = atan2f(sqrtf(a), sqrtf(1 - a));

	return 6373 * c;
}

void heapSort(Array& myArrayAdress, int size) {
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(myArrayAdress, size, i);

	for (int i = size - 1; i >= 0; i--) {
		myArrayAdress.swap(0, i);
		heapify(myArrayAdress, i, 0);
	}
}

void heapify(Array& myArrayAdress, int max, int low) {
	int largest = low;
	int left = 2 * low + 1;
	int right = 2 * low + 2;

	if (left < max && myArrayAdress.retrieve(left).getDistance() > myArrayAdress.retrieve(largest).getDistance())
		largest = left;

	if (right < max && myArrayAdress.retrieve(right).getDistance() > myArrayAdress.retrieve(largest).getDistance())
		largest = right;

	if (largest != low) {
		myArrayAdress.swap(low, largest);
		heapify(myArrayAdress, max, largest);
	}
}


void printFile(Array& myArrayAdress, int size) {
	cout << "printFile function is working..." << endl;
	ofstream outFile("sorted.txt");

	for (int i = 0; i < size; i++) {
		outFile << myArrayAdress.retrieve(i).getCity() << " " << myArrayAdress.retrieve(i).getDistance() << endl;
	}
	cout << "printFile function is done." << endl;
}