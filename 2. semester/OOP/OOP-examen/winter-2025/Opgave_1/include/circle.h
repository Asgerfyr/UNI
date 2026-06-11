#pragma once

#include "point.h"

class circle {

    friend std::ostream &operator<<(std::ostream &, const circle &);

public:
    circle(point, double);
    circle operator*(const double &s);
    friend bool operator&&(const circle &left, const circle &right);

private:
    point center_;
    double radius_;
};


bool operator&&(const circle &left, const circle &right);