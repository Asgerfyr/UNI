#include <iostream>
#include "point.h"
#include "square.h"
#include "tests.h"

int main() {
    std::cout << "***** Test Results from: test_point_add ****" << "\n";
    test_point_add();
    std::cout << "\n" << "\n";

    std::cout << "**** Test Results from: test_point_stream ****" << "\n";
    test_point_stream();
    std::cout << "\n" << "\n";

    std::cout << "**** Test Results from: test_square_add ****" << "\n";
    test_square_add();
    std::cout << "\n" << "\n";

    std::cout << "**** Test Results from: test_square_stream ****" << "\n";
    test_square_stream();
    return 0;
}