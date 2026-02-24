//
// Created by Asger on 12/02/2026.
//
#include "cmath"
#include "string"
#include "item.h"


Item::Item(const int &_id, const std::string &_name, const double &_price): id_{_id}, name_{_name}, price_{_price} {}


std::string Item::to_string() const {
    return name_ + " " + std::to_string(std::round(price_*100)/100);
}