#pragma once

#include "point.h"
#include <ostream>

class square {

public:
    square(const point &, double);
    point get_center() const;
    double area() const;
    [[nodiscard]] friend square operator+(const square &left, const square &right);

    friend std::ostream& operator<<(std::ostream &os, const square &square);

private:
    point center_;
    double size_;

};