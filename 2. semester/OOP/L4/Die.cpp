//
// Created by Asger on 22/02/2026.
//

#include "Die.h"
#include <random>
#include <vector>
#include <string>


Die::Die(){};

void Die::roll() {
    value_ = dist_(rd_);
    this->inc_total();
}

int Die::get_value()const {
    return value_;
}

void Die::inc_total() {
    total_throws_++;
    total_[value_-1]++;
}

void Die::reset_total() {
    total_throws_ = 0;
    total_ = std::vector<int>{0,0,0,0,0,0};
}

int Die::get_total_throws() const {
    return total_throws_;
}

std::string Die::get_total() const {
    std::string return_string = "[";
    int i{};
    for (int x : total_) {
        return_string += std::to_string(x);
        if (i != 5)return_string += ",   ";
        i++;
    }
    return_string += "]";
    return return_string;
}

std::vector<double> Die::get_frequency() const {
    std::vector<double> frequency;
    for (int x : total_) {
        frequency.push_back((double)total_throws_/(double)x);
    }
    return frequency;
}

double Die::get_mean() const{
    long sum{};
    int i{};
    for (int x : total_) {
        sum += (i+1)*x;
        i++;
    }
    return (double)sum/(double)total_throws_;
}
