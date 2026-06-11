#pragma once

#include "point.h"
#include <ostream>

class square {

public:
    square(const point &, double);
    point get_center() const;
    double area() const;

private:
    point center_;
    double size_;

};