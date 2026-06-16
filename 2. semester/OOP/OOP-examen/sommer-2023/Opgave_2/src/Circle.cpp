#include "Circle.h"
#include <iostream>
#include <cmath>


Circle::Circle(const Point& center, double radius):
    Shape(), center(center), radius(radius){}


void Circle::print() const{
    std::cout << "Cirkel med center " 
    << center.x << ", " << center.y << std::endl;
    std::cout << "Radius: " << radius << '\n';
    std::cout << "Areal: " << area() << '\n';
    std::cout << "Omkreds: " << circumference() << '\n';
}

double Circle::area() const{
    double pi = 2*acos(0.0); //difiner pi
    return pow(radius,2)*pi;
}

double Circle::circumference() const{
    double pi = 2*acos(0.0); //difiner pi
    return (radius)*2*pi;
}