#pragma once

#include <set>
#include "data_collector.h"

class unique_sorted_collector : public data_collector{

protected:
    std::vector<double> prepare() const override; 
    void collect(double value) override;

private:
    std::set<double> data_;
};