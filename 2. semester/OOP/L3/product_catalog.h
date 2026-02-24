//
// Created by Asger on 12/02/2026.
//

#ifndef L3_PRODUCT_CATALOG_H
#define L3_PRODUCT_CATALOG_H

#include <vector>
#include <string>
#include "item.h"

class Product_catalog {

public:

    Product_catalog();

    void add_item(const int &_id, const std::string &_name, const double &_price);

    const Item* get_item(const int& _id) const;

private:
    std::vector<Item> items_;
};


#endif //L3_PRODUCT_CATALOG_H