#pragma once

#include <vector>
#include "loan.h"

class account {
public:
    void add_loan(loan* );
    std::string all_schemes();
private:
    std::vector<loan *> loans_;
};