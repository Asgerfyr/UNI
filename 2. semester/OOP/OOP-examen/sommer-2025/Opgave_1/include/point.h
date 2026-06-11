#pragma once
#include <ostream>
class point {
public:
    [[nodiscard]] point operator+(const point &other) const;


    double x;
    double y;
};


std::ostream& operator<<(std::ostream &os, const point &point);