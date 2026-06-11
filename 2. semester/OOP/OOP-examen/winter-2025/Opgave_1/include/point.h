#pragma once

#include <iostream>

class point {





public:
    point(double, double);

    double norm();

    double x;
    double y;
};


point operator*(double, const point &);

point operator+(const point &, const point &);

point operator-(const point &, const point &);

std::ostream& operator<<(std::ostream &os, const point &p);
