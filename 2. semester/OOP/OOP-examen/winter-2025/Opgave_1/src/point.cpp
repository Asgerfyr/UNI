#include "point.h"
#include <cmath>

using namespace std;

point::point(double x, double y) : x(x), y(y) {}


double point::norm(){
    return sqrt(pow(x,2)+pow(y,2));
}


point operator+(const point &left, const point &right) {
    return point(left.x + right.x, left.y + right.y);
}

point operator*(double s, const point &point) {
    return {s * point.x, s * point.y};
}

point operator-(const point &left, const point &right){
    return left+(-1*right);
}

std::ostream& operator<<(std::ostream &os, const point &p){
    os << "(" << p.x << "," << p.y << ")" << std::endl;
    return os;
}
