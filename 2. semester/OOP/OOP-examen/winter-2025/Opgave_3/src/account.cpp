#include "account.h"
#include <sstream>

void account::add_loan(loan *loan) {
    loans_.push_back(loan);

}

std::string operator*(const std::string &str, const int mult){
    if(mult <= 0) throw std::invalid_argument("mult is under 0");
    std::string multiple_string;
    for(int i = 0; i < mult; i ++){
        multiple_string += str;
    }
    return multiple_string;
}

std::string account::all_schemes(){
    std::ostringstream all_schemes_str;

    for (auto it = loans_.begin(); it != loans_.end(); ++it) {
        all_schemes_str << std::string("=")*20 << std::endl;
        all_schemes_str << "loan " << std::distance(loans_.begin(), it)+1 << ":" << std::endl;
        all_schemes_str << (*it)->get_payment_scheme();
        all_schemes_str << std::string("=")*20 << std::endl;
        all_schemes_str << std::endl << std::endl;
    }

    return all_schemes_str.str();
}