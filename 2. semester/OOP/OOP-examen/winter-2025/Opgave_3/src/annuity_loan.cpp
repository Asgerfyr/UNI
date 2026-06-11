#include "annuity_loan.h"
#include <stdexcept>


annuity_loan::annuity_loan(const std::string &name, double principal, double interest_rate, unsigned int terms):loan(name,principal,interest_rate,terms){
    payment_ = calculate_payment(principal,interest_rate,terms);
}

double annuity_loan::calculate_payment(double principal, double interest_rate, unsigned int terms) {
    return principal * interest_rate * pow((1 + interest_rate), terms) / (pow((1 + interest_rate), terms) - 1);
}

double annuity_loan::get_payment(unsigned int terms) const{
    if(terms < 1 || terms > get_terms()) throw std::invalid_argument("terms is not in the right range in annuity, got: " + std::to_string(terms));
    return payment_;
}