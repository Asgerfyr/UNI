#pragma once

#include <cmath>
#include "loan.h"

class annuity_loan : public loan{
public:
    annuity_loan(const std::string &name, double principal, double interest_rate, unsigned int terms);


private:
    double payment_;

    static double calculate_payment(double principal, double interest_rate, unsigned int terms);

    double get_payment(unsigned int terms) const override;
};