#include <iostream>
#include "test_1.h"

int main() {
    std::cout << "Begin Pre implemented test  of to_string()" << "\n";
    test_to_string();
    std::cout << "**************************" << "\n\n";

    std::cout << "Begin test_add_matrices" << "\n";
    test_add();
    std::cout << "**************************" << "\n\n";

    std::cout << "Begin test_stream" << "\n";
    test_stream();
    std::cout << "**************************" << "\n\n";

    std::cout << "Begin test_exception_get" << "\n";
    test_exception();
    std::cout << "**************************" << "\n\n";

    return 0;
}
