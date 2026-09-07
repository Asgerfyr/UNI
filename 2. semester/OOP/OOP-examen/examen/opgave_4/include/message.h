#pragma once
#include <string>
#include <vector>

class message {
public:
    virtual ~message() = default;
    virtual std::string send() const = 0;
};
