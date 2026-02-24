#include <iostream>
#include "item.h"
#include "product_catalog.h"




int main() {

        Product_catalog product_catalog;

        product_catalog.add_item(0,"some",75.54);
        product_catalog.add_item(1,"min",75.8);
        product_catalog.add_item(2,"fac",733.548);

        std::cout << "object 1: " <<product_catalog.get_item(0)->to_string() << std::endl;

        std::cout << "object 1: " <<product_catalog.get_item(1)->to_string() << std::endl;

}

