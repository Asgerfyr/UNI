#include "Amount.h"
#include <sstream>
#include <cmath>

Amount::Amount(double amount, Currency &currency): amount(amount), currency(currency){}


Amount Amount::operator+(Amount &other){
    double new_amount = this->currency.toStandardCurrency(this->amount);
    new_amount += other.currency.toStandardCurrency(other.amount);
    new_amount = this->currency.fromStandardCurrency(new_amount);
    return{new_amount, this->currency};
}

std::string Amount::toString() const{
    std::stringstream ret_str; 
    ret_str << this->amount << " " << this->currency.getSymbol();
    return ret_str.str();
}




//Opgave 1 h)
bool operator==(Amount &left, Amount &right){
    double l_amount = left.currency.toStandardCurrency(left.amount);
    double r_amount = right.currency.toStandardCurrency(right.amount);
    double diff = abs(l_amount-r_amount);
    return diff < 0.001;
}
