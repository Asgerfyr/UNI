#include "measurements.h"

void measurements::add(double value) {
    data_.push_back(value);
}

double measurements::average() const {
    if (data_.empty()) {
        throw std::length_error("No data to calculate average");
    }
    double sum{};
    for (double v: data_) {
        sum = sum + v;
    }
    return sum / static_cast<double>(data_.size());
}

double measurements::latest() const {
    if (data_.empty()) {
        throw std::length_error("No data to retrieve");
    }
    return data_.back();
}

std::vector<double> measurements::sorted() const {
    if (data_.empty()) {
        throw std::length_error("Nothing to sort");
    }
    std::vector<double> copy = data_;
    std::sort(copy.begin(), copy.end());
    return copy;
}

double measurements::max() const {
    return *std::max_element(data_.begin(), data_.end());
}