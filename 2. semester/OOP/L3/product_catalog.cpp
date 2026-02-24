//
// Created by Asger on 12/02/2026.
//

#include "product_catalog.h"


Product_catalog::Product_catalog() {}

void Product_catalog::add_item(const int &_id, const std::string &_name, const double &_price) {
    items_.push_back(Item(_id, _name, _price));
}

const Item* Product_catalog::get_item(const int& _id) const{
    return &(items_[_id]);
}
