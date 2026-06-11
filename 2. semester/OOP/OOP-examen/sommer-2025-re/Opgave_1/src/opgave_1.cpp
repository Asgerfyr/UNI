#include <iostream>
#include "tests.h"

int main() {
    std::cout<<"*******test_box_volume**********"<<"\n";
    test_box_volume();
    std::cout<<"********************************"<<"\n"<<"\n";

    std::cout<<"*******test_box_equals_operator**********"<<"\n";
    test_box_equals_operator();
    std::cout<<"********************************"<<"\n"<<"\n";

    std::cout<<"*******test_box_less_than_operator**********"<<"\n";
    test_box_less_than_operator();
    std::cout<<"********************************"<<"\n"<<"\n";

    std::cout<<"*******test_boxes_to_string**********"<<"\n";
    test_boxes_to_string();
    std::cout<<"********************************"<<"\n"<<"\n";

    std::cout<<"*******test_boxes_to_string_sorted**********"<<"\n";
    test_boxes_to_string_sorted();
    std::cout<<"********************************"<<"\n"<<"\n";

    return 0;
}