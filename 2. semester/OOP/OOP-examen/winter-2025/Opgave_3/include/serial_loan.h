#pragma once

#include "loan.h"

class serial_loan : public loan{
public:
    serial_loan(const std::string &name, double principal, double interest_rate, unsigned int terms);

private:
    double calculate_payment(unsigned int term) const;
    double get_payment(unsigned int terms) const override;
};