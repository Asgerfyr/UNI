#include "test_account.h"
#include "account.h"
#include "annuity_loan.h"
#include "serial_loan.h"
#include <iostream>

void test_account_all_schemes() {

    account acc;

    annuity_loan a{"Annuity_Loan",500,0.05,5};
    acc.add_loan(&a);
    serial_loan s{"Serial_Loan",700.,0.03,11};
    acc.add_loan(&s);

    std::cout << acc.all_schemes(); 

}