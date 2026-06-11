#include <iostream>
#include "container_template.h"
#include "test_int_container.h"
#include "test_container_template.h"
#include "test_string_writer.h"
#include "test_string_writer_template.h"


int main() {

    std::cout << "Pre implemented test of string_writer" << "\n";
    test_as_string();
    std::cout << "\n\n";
    std::cout << "Pre implemented test of to_string on int_container" << "\n";
    test_to_string();
    std::cout << "\n\n";
    std::cout << "Pre implemented test of to_string_sort on int_container" << "\n";
    test_to_string_sorted();
    std::cout << "\n\n";
    std::cout << "Implement test of as_string in template-funktion" << "\n";
    test_template_as_string();
    std::cout << "\n\n";
    std::cout << "Implement test of to_string on persons in template container" << "\n";
    test_template_to_string_person();
    std::cout << "\n\n";
    std::cout << "Implement test of to_string_sorted on persons in template container" << "\n";
    test_template_to_string_sorted_person();
    return 0;
}