#pragma once
#include <string>

class cat {
public:
    cat(const std::string &, int age);

    bool operator==(const cat &) const;

private:
    int age_;
    std::string name_;
};
