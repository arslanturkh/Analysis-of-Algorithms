#pragma once

#ifndef CITY
#define CITY

#include <iostream>
using namespace std;

class City {
public:
	City();

	City(string initCity, float linitLatitude, float initLongitude, float initDistance);

	string getCity() ;

	float getLatitude() ;

	float getLongitude() ;

	float getDistance() ;

	void setDistance(float initDistance);

private:
	string city;
	float latitude;
	float longitude;
	float distance;
};
#endif // CITY
