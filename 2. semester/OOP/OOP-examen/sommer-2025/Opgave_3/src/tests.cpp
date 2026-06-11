#include "tests.h"
#include "csv_unique_sorted_collector.h"
#include "json_collector.h"
#include <iostream>

void test_unique_sorted_collector() {
    unique_sorted_collector_test c{};
    c.receive(3);
    c.receive(6);
    c.receive(1);
    c.receive(2);
    c.receive(6);
    c.receive(1);
    
    std::cout << c.print() << '\n';
}

void test_csv_unique_sorted_collector() {
    csv_unique_sorted_collector c{200};
    c.receive(53);
    c.receive(5);
    c.receive(35);
    c.receive(4);
    c.receive(445);
    c.receive(201);
    c.receive(2);
    c.receive(4);
    c.receive(35);
    
    std::cout << c.print() << '\n';
}

void test_json_collector() {
    json_collector j{std::string("temp"),10,200};
    j.receive(53);
    j.receive(5);
    j.receive(35);
    j.receive(4);
    j.receive(445);
    j.receive(201);
    j.receive(2);
    j.receive(4);
    j.receive(35);
    
    std::cout << j.print() << '\n';
}