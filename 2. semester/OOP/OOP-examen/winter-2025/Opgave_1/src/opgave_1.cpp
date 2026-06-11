#include "test_point.h"
#include "test_circle.h"


int main() {
    std::cout << "Implement test_point_streaming_operator" << "\n";
    test_point_streaming_operator();
    std::cout << "" << "\n\n";

    std::cout << "Implement test_point_subtraction_operator" << "\n";
    test_point_subtraction_operator();
    std::cout << "" << "\n\n";

    std::cout << "Implement test_point_norm" << "\n";
    test_point_norm();
    std::cout << "\n\n";

    std::cout << "Implement test_circle_streaming_operator" << "\n";
    test_circle_streaming_operator();
    std::cout << "\n\n";

    std::cout << "Implement test_circle_scale_operator" << "\n";
    test_circle_scale_operator();
    std::cout << "\n\n";

    std::cout << "Implement test_circle_intersect_operator" << "\n";
    test_circle_intersect_operator();
    std::cout << "\n\n";
    
    return 0;
}