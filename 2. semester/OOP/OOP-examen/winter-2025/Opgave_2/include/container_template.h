#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include "string_writer_template.h"

template<typename T>
class container_template {
public:
    void add(T);
    std::string to_string() const;
    std::string to_string_sorted() const;

private:
    std::vector<T> data_;
};

template<typename T>
void container_template<T>::add(T i) {
    data_.push_back(i);
}

template<typename T>
std::string container_template<T>::to_string() const {
    return as_string(data_.begin(), data_.end());
}

template<typename T>
std::string container_template<T>::to_string_sorted() const {
    auto sorted = data_;
    std::sort(sorted.begin(), sorted.end());
    return as_string(sorted.begin(), sorted.end());
}



