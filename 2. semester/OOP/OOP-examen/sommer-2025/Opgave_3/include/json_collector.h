#pragma once

#include "data_collector.h"
#include <string>
#include <vector>

class json_collector {
public:
    json_collector(const std::string &value_name, double low, double high);

private:

    std::string value_name_;
    std::pair<double, double> range_;
    std::vector<double> data_;
};