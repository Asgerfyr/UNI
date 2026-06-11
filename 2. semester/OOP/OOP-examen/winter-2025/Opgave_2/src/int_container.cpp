#include "int_container.h"
#include "string_writer.h"
#include <algorithm>

void int_container::add(int i) {
    data_.push_back(i);
}

std::string int_container::to_string() const {
    return as_string(data_.begin(), data_.end());
}

std::string int_container::to_string_sorted() const {
    auto sorted = data_;
    std::sort(sorted.begin(), sorted.end());
    return as_string(sorted.begin(), sorted.end());
}