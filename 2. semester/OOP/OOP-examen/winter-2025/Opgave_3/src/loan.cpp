#include "loan.h"
#include <sstream>

loan::loan(const std::string &name, double principal, double interest_rate, unsigned int terms)
        : name_(name), principal_(principal), interest_rate_(interest_rate), terms_(terms) {}

double loan::get_principal() const {
    return principal_;
}

unsigned int loan::get_terms() const {
    return terms_;
}

double loan::get_rate() const {
    return interest_rate_;
}

std::string loan::get_name() const {
    return name_;
}

double loan::get_total_payment() const {
    double total = 0; 
    for(unsigned int i = 1; i < terms_+1; i++){
        total += get_payment(i);
    }
    return total;
}

std::string loan::get_payment_scheme() const {
    std::ostringstream scheme;
    scheme << "Loan:" << name_ << std::endl;
    scheme << "Principal:" << principal_ << std::endl;
    scheme << "Rate:" << interest_rate_ << std::endl; 
    
    for(unsigned int i = 1; i < terms_+1; i++){
        scheme << "Term:" << get_payment(i) << std::endl;
    }

    scheme << "Total:" << get_total_payment() << std::endl;
    return scheme.str();
}

