#include "circle.h"

circle::circle(point center, double radius) : center_(center), radius_(radius) {}

// implement scale operator
circle circle::operator*(const double &s){
    return {center_,s*radius_};
}


// implement intersect operator
bool operator&&(const circle &left, const circle &right){
    return (left.center_ - right.center_).norm() <= left.radius_ + right.radius_;
}

std::ostream &operator<<(std::ostream &os, const circle &circle) {
    os << "center:" << "(" << circle.center_.x << "," << circle.center_.y << ")" << " radius:" << circle.radius_;
    return os;
}