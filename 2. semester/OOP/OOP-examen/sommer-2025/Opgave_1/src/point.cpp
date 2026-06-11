#include "point.h"


[[nodiscard]] point point::operator+(const point &right) const{
    return {(this->x+right.x)/2, (this->y+right.y)/2};
}