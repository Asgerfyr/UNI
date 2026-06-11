#include <iostream>
#include "tests.h"

int main() {
    std::cout << "********test_log***************" << "\n";
    test_log();
    std::cout << "\n" << "**********test_log_template*************" << "\n";
    test_log_template_string();
    std::cout << "\n" << "***********test_log_template_log_entry************" << "\n";
    test_log_template_log_entry();
    return 0;
}