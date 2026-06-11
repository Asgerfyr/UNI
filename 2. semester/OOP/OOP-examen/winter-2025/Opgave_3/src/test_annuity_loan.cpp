#include "test_annuity_loan.h"
#include "annuity_loan.h"
#include <iostream>

void test_annuity_get_payment_scheme() {
    annuity_loan a{"Annuity_Loan",1000,0.03,10};
    std::cout << a.get_payment_scheme();
}