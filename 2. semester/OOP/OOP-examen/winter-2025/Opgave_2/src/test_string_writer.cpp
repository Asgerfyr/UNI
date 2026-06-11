#include "test_string_writer.h"
#include <vector>
#include <iostream>
#include "string_writer.h"

void test_as_string() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    auto res = as_string(v.begin(), v.end());
    std::cout << res;
}