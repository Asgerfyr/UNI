#include "cat.h"

cat::cat(const std::string &name, const int age) : name_(name), age_(age) {
}

bool cat::operator==(const cat &left) const {
    return name_ == left.name_;
}
