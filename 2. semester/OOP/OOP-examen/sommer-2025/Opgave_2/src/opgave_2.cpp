#include <iostream>
#include "tests.h"
int main() {
    std::cout << "**** Test Results from: test_measurements ****" << "\n";
    test_measurements();
    std::cout << "\n" << "\n";

    std::cout << "**** test_template_measurements ****" << "\n";
    test_template_measurements();
    std::cout << "\n" << "\n";

    std::cout << "**** test_template_measurements_on_temperature ****" << "\n";
    test_template_measurements_on_temperature();
    return 0;
}