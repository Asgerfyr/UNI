#include "test_string_writer.h"
#include <list>
#include <iostream>
#include "string_writer_template.h"
#include "person.h"

void test_template_as_string() {
    std::list<person> p = {
        person("hans",50), 
        person("anne",20), 
        person("lars",15), 
        person("bo",32)
       };
    auto res = as_string(p.begin(), p.end());
    std::cout << res;
}