#include "point.h"


[[nodiscard]] point point::operator+(const point &other) const{
    return {(this->x+other.x)/2, (this->y+other.y)/2};
}

std::ostream& operator<<(std::ostream &os, const point &point){
    os << "(" << point.x << "," << point.y << ")";
    return os;
}