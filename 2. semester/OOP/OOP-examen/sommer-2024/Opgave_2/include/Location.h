#pragma once

class Location
{
public:
	Location(double, double);
	bool operator==(const Location&) const;
	double longitude;
	double latitude;
};
