#include "test_3.h"
#include <list>
#include <iostream>
#include "cat.h"
#include "contains.h"

void test_contains() {
    std::list<cat> container;
    cat c1{std::string("pete"), 3};
    cat c2{std::string("kevin"), 9};
    cat c3{std::string("bob"), 1};
    cat c4{std::string("kalypso"), 10};
    cat c5{std::string("jens"), 4};
    cat c6{std::string("puk"), 15};

    //cat to not put in container
    cat c7{std::string("miav cat"), 50};

    container.emplace_back(c1);
    container.emplace_back(c2);
    container.emplace_back(c3);
    container.emplace_back(c4);
    container.emplace_back(c5);
    container.emplace_back(c6);

    std::cout << "cat 1 to 6 is added in the container but 7 is not" << "\n\n";

    std::cout << "Tests with contains function expected value in ()" << "\n\n";

    std::cout << "Test to see if cat 3 is in container (True): " << '\n';
    std::cout << (contains<std::list<cat>,cat>(container,c3)?"True":"False") << "\n\n";

    std::cout << "Test to see if cat 7 is in container (False): " << '\n';
    std::cout << (contains<std::list<cat>,cat>(container,c7)?"True":"False") << '\n';
}
