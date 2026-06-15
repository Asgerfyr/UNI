#pragma once
#include "Currency.h"
#include <string>
//Opgave 1 b)

class Amount
{
public:
    Amount(double amount, Currency &currency);
    Amount operator+(Amount &other);
    std::string toString() const;
    friend bool operator==(Amount &left, Amount &right);
    
private:
    double amount;
    Currency currency;
};


bool operator==(Amount &left, Amount &right);