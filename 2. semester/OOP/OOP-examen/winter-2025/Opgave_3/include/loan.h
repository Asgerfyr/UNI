#pragma once

#include <string>

class loan {
public:
    std::string get_payment_scheme() const;


protected:
    loan(const std::string &name, double principal, double interest_rate, unsigned int terms);

    double get_total_payment() const;

    double get_principal() const;

    unsigned int get_terms() const;

    std::string get_name() const;

    double get_rate() const;

    virtual double get_payment(unsigned int terms) const {return 0;};
    
private:
    std::string name_;
    double principal_;
    double interest_rate_;
    unsigned int terms_;
};