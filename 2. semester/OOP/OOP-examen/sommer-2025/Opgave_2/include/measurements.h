#pragma once

#include <vector>
#include <stdexcept>
#include <algorithm>

class measurements {
public:
    void add(double value);

    double average() const;

    double latest() const;

    std::vector<double> sorted() const;

    double max() const;

private:
    std::vector<double> data_;
};