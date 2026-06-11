#include "test_circle.h"

void test_circle_streaming_operator() {
    std::cout << "test_circle_streaming_operator" << "\n";
    circle c(point(1, 2), 4);
    std::cout << c;
}

void test_circle_scale_operator() {
    circle c(point(1, 2), 4);
    std::cout << c*5;
}

void test_circle_intersect_operator() {
    circle A{point(3,4),2};
    circle B{point(1,2),1};
    circle C{point(0,0),1};

    std::cout << "Test: do C and B overlap = " << (C && B) << std::endl;
    std::cout << "Test: do A and B overlap = " << (A && B) << std::endl;

}
