#include "cities.h"
#include <cassert>	
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

City::City() {
	city = " ";
	latitude = -1;
	longitude = -1;
	distance = -1;
}

City::City(string initCity, float linitLatitude, float initLongitude, float initDistance) {
	city = initCity;
	latitude = linitLatitude;
	longitude = initLongitude;
	distance = initDistance;
}

string City::getCity()  {
	return city;
}

float City::getLatitude()  {
	return latitude;
}

float City::getLongitude()  {
	return longitude;
}

float City::getDistance()  {
	return distance;
}

void City::setDistance(float initDistance) {
	distance = initDistance;
}