#include "square.h"
#include <cmath>

square::square(const point &center, double size) : center_{center}, size_(size) {}

point square::get_center() const {
    return center_;
}

double square::area() const {
    return pow(size_, 2);
}


square operator+(const square &left, const square &right){
    return{left.center_+right.center_, sqrt(left.area()+right.area())};
}

std::ostream& operator<<(std::ostream &os, const square &square){
    os << "Center:" << square.center_ << " Area:" << square.area();
    return os;
}

