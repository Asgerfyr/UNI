#include "json_collector.h"

json_collector::json_collector(const std::string &value_name, double low, double high) : value_name_(value_name),
                                                                                         range_(std::pair(low, high)) {}

bool json_collector::filter(double value) const{
    return value > range_.first && value < range_.second;
}

void json_collector::collect(double value) {
    data_.emplace_back(value);
    return;
}

std::vector<double> json_collector::prepare() const{
    return data_;
}

std::string json_collector::format(double value) const{
    return "{\n\"" + value_name_ + "\":" + std::to_string(value) + "\n}";
}