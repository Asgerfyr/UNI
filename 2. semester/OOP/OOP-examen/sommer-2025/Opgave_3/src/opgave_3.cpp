
#include <iostream>
#include "tests.h"

int main() {
    std::cout << "**** Test Results from: test_unique_sorted_collector ****" << "\n";
    test_unique_sorted_collector();
    std::cout << "\n" << "\n";

    std::cout << "**** Test Results from: test_csv_unique_sorted_collector ****" << "\n";
    test_csv_unique_sorted_collector();
    std::cout << "\n" << "\n";

    std::cout << "**** Test Results from: test_json_collector ****" << "\n";
    test_json_collector();
    return 0;
}
