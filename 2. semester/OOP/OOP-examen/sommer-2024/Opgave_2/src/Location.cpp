#include "Location.h"

Location::Location(const double longitude, const double latitude) : longitude(longitude), latitude(latitude)
{
}

bool Location::operator==(const Location& other) const
{
	return other.latitude == latitude && other.longitude == longitude;
}
