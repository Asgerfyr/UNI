#include "test_serial_loan.h"
#include "serial_loan.h"
#include <iostream>

void test_serial_get_payment_scheme() {
    serial_loan s{"Serial_Loan",1000.,0.03,10};
    std::cout << s.get_payment_scheme();
}