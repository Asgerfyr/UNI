#pragma once

#include <vector>
#include <string>
#include "box.h"

class boxes {
public:
    void add_box(const box &);

    std::string to_string() const;
    std::string to_string_sorted() const;

private:
    std::vector<box> boxes_;
};