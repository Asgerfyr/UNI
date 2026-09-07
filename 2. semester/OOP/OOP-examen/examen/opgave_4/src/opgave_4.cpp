#include <iostream>

#include "test_4.h"

int main() {
    std::cout << "Begin test_send_email" << "\n";
    test_send_email();
    std::cout << "\n**************************" << "\n\n";

    std::cout << "Begin test_send_sms" << "\n";
    test_send_sms();
    std::cout << "\n**************************" << "\n\n";

    std::cout << "Begin test_dispatcher" << "\n";
    test_dispatcher();
    std::cout << "**************************" << "\n\n";
}
