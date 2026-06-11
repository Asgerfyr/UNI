#pragma once
#include <ostream>
class point {
public:
    [[nodiscard]] point operator+(const point &right) const;


    double x;
    double y;
};
