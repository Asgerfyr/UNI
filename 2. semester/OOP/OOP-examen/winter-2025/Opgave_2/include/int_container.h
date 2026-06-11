#pragma once

#include <vector>
#include <string>

class int_container {
public:
    void add(int);
    std::string to_string() const;
    std::string to_string_sorted() const;

private:
    std::vector<int> data_;
};