#pragma once

#include <set>
#include "unique_sorted_collector.h"


class csv_unique_sorted_collector : public unique_sorted_collector{
public:
    explicit csv_unique_sorted_collector(double upper_limit);

protected:
    bool filter(double value) const override; 
    std::string format(double value) const override; 

private:
    double upper_limit_;
};