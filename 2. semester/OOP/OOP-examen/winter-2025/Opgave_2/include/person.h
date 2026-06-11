#pragma once

#include <string>
#include <iostream>
class person {
public:
    person(const std::string &, int age);

    std::string name;
    int age;
};

bool operator<(const person &, const person &);
std::ostream& operator<<(std::ostream &,const person&);