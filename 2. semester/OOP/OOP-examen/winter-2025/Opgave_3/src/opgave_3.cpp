#include <iostream>
#include "annuity_loan.h"
#include "serial_loan.h"
#include "account.h"
#include "test_annuity_loan.h"
#include "test_serial_loan.h"
#include "test_account.h"

int main() {
    std::cout << "Implement test of annuity loan get_payment_scheme" << "\n";
    test_annuity_get_payment_scheme();
    std::cout << "\n\n";

    std::cout << "Implement test of serial loan get_payment_scheme" << "\n";
    test_serial_get_payment_scheme();
    std::cout << "\n\n";

    std::cout << "Implement test of account all_schemes" << "\n";
    test_account_all_schemes();
    return 0;
}