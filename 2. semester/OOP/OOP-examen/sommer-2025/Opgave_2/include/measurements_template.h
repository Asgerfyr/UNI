#pragma once

#include <vector>
#include <stdexcept>
#include <algorithm>

template<typename T>
class measurements_template {
    public:
    void add(T value);

    T average() const;

    T latest() const;

    std::vector<T> sorted() const;

    T max() const;

private:
    std::vector<T> data_;
};

template<typename T>
void measurements_template<T>::add(T value) {
    data_.push_back(value);
}

template<typename T>
T measurements_template<T>::average() const {
    if (data_.empty()) {
        throw std::length_error("No data to calculate average");
    }
    T sum{};
    for (T v: data_) {
        sum = sum + v;
    }
    return sum / static_cast<double>(data_.size());
}

template<typename T>
T measurements_template<T>::latest() const {
    if (data_.empty()) {
        throw std::length_error("No data to retrieve");
    }
    return data_.back();
}

template<typename T>
std::vector<T> measurements_template<T>::sorted() const {
    if (data_.empty()) {
        throw std::length_error("Nothing to sort");
    }
    std::vector<T> copy = data_;
    std::sort(copy.begin(), copy.end());
    return copy;
}

template<typename T>
T measurements_template<T>::max() const {
    return *std::max_element(data_.begin(), data_.end());
}