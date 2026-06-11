#pragma once

#include "data_collector.h"
#include <string>
#include <vector>

class json_collector : public data_collector {
public:
    json_collector(const std::string &value_name, double low, double high);

private:
    bool filter(double value) const override;
    void collect(double value) override;
    std::vector<double> prepare() const override;
    std::string format(double value) const override;

    std::string value_name_;
    std::pair<double, double> range_;
    std::vector<double> data_;
};