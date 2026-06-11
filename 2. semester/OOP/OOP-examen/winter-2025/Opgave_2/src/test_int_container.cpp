#include "test_int_container.h"
#include "int_container.h"
#include <iostream>

void test_to_string() {
    int_container c;
    c.add(2);
    c.add(9);
    c.add(3);
    c.add(10);
    c.add(6);
    std::cout << c.to_string() << "\n";
}

void test_to_string_sorted() {
    int_container c;
    c.add(2);
    c.add(9);
    c.add(3);
    c.add(10);
    c.add(6);
    std::cout << "Sorted: " << c.to_string_sorted() << "\n";
    std::cout << "Original:" << c.to_string() << "\n";
}

