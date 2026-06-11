#include "person.h"

person::person(const std::string &name, int age) : name(name), age(age) {}

bool operator<(const person &left, const person &right) {
    return left.name < right.name;
}

std::ostream &operator<<(std::ostream &os, const person &person) {
    os << "(Name:" << person.name << " Age:" << person.age<<")";
    return os;
}