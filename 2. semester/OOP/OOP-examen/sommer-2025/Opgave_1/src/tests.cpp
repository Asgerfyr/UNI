#include "point.h"
#include "square.h"
#include <iostream>

void test_point_add() {
    point a{2,2}, b{4,6};
    point c = a+b;
    std::cout << "exspect (3,4): (" << c.x << "," << c.y << ")" << '\n';
}

void test_point_stream() {
    point a{2,2}, b{4,6};
    point c = a+b;
    std::cout << "exspect (3,4): " << c << '\n';
}

void test_square_add() {
    point a{2,2}, b{4,6};
    square s1{a,3}, s2{b,4}; 
    square s3 = s1+s2;
    std::cout << "exspect C = (3,4) A = 25: \nC = " << s3.get_center() << " A = " << s3.area() << '\n';
}

void test_square_stream() {
    point a{2,2}, b{4,6};
    square s1{a,3}, s2{b,4}; 
    square s3 = s1+s2;
    std::cout << "exspect C = (3,4) A = 25: \n" << s3 << '\n';
}