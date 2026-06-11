#include "test_point.h"

void test_point_streaming_operator() {
    point p{5,8};
    std::cout << p;
}

void test_point_subtraction_operator() {
    point p1{4,6}, p2{2,3};
    std::cout << p1-p2;
}

void test_point_norm() {
    point p{4,3};
    std::cout << p.norm();
}