#include "square.h"
#include <cmath>

square::square(const point &center, double size) : center_{center}, size_(size) {}

point square::get_center() const {
    return center_;
}

double square::area() const {
    return pow(size_, 2);
}