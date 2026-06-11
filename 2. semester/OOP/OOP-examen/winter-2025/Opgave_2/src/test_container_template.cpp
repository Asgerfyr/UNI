#include "test_container_template.h"
#include "container_template.h"
#include <iostream>
#include "person.h"

void test_template_to_string_person() {
    container_template<person> c;
    c.add(person("anders",22));
    c.add(person("bob",33));
    c.add(person("carl",44));
    c.add(person("dani",55));
    c.add(person("erik",66));
    std::cout << c.to_string() << "\n";
}

void test_template_to_string_sorted_person() {
    container_template<person> c;
    c.add(person("erik",66));
    c.add(person("dani",55));
    c.add(person("carl",44));
    c.add(person("bob",33));
    c.add(person("anders",22));
    std::cout << "Sorted: " << c.to_string_sorted() << "\n";
    std::cout << "Original:" << c.to_string() << "\n";
}