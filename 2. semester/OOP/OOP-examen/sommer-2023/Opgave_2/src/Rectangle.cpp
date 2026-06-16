#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(const Point& corner, double height, double width):
    Shape(), upperleftcorner(corner), height(height), width(width){}


void Rectangle::print() const{
    std::cout << "Rectangle med upper left corner " 
    << upperleftcorner.x << ", " << upperleftcorner.y << std::endl;
    std::cout << "Hoejde: " << height << '\n';
    std::cout << "Bredde: " << width << '\n';
    std::cout << "Areal: " << area() << '\n';
    std::cout << "Omkreds: " << circumference() << '\n';
}

double Rectangle::area() const{
    return width*height;
}

double Rectangle::circumference() const{
    return (width+height)*2;
}