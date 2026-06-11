#include "serial_loan.h"
#include <stdexcept>


serial_loan::serial_loan(const std::string &name, double principal, double interest_rate, unsigned int terms): loan(name, principal, interest_rate, terms){}



double serial_loan::calculate_payment(unsigned int term) const {
    auto remaining = get_principal() - (term - 1) * get_principal() / get_terms();
    auto interest = get_rate() * remaining;
    return get_principal() / get_terms() + interest;

}


double serial_loan::get_payment(unsigned int terms) const {
    if(terms < 1 || terms > get_terms()) throw std::invalid_argument("terms is not in the right range in serial, got: " + std::to_string(terms));
    return calculate_payment(terms);
}