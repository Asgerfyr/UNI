#include "Drawing.h"
#include <iostream>

Drawing::Drawing(int id): id(id){}

Drawing::~Drawing(){
    for (auto it = shapes.begin(); it != shapes.end(); ++it) {
        delete *it;
    }
}

void Drawing::print() const{
    std::cout << "Drawing with " <<  shapes.size() << " shapes" << std::endl;
    std::cout << "Areal: " << area() << '\n';
    std::cout << "circumference: " << circumference() << '\n';
    
    for (auto it = shapes.begin(); it != shapes.end(); ++it) {
        std::cout << "Shape " << std::distance(shapes.begin(), it)+1 << ":\n";
        (*it)->print();
        std::cout << '\n';
    }
}

double Drawing::area() const{
    double area_tot = 0;
    for (auto it = shapes.begin(); it != shapes.end(); ++it) {
        area_tot += (*it)->area();
    }
    return area_tot;
}

double Drawing::circumference() const{
    double circumference_tot = 0;
    for (auto it = shapes.begin(); it != shapes.end(); ++it) {
        circumference_tot += (*it)->circumference();
    }
    return circumference_tot;
}


void Drawing::add(Shape* shape){
    shapes.emplace_back(shape);
}