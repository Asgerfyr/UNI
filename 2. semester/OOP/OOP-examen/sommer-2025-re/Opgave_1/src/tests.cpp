#include "tests.h"
#include "box.h"
#include "boxes.h"
#include <vector>
#include <cassert>
#include <iostream>

// Pre-implemented test of volume
void test_box_volume() {
    box b{1.4, 2.3, 3.9};
    // you can use asserts as test-tool,
    // but it is not required! assert simply takes a bool expression as input and fails if it is false
    // and is in include-file <cassert>
    assert(std::abs(b.volume() - 12.558) < box::delta);
}

void test_box_equals_operator() {
    box b1{1.4, 2.3, 3.9};
    box b2{2.3, 1.4, 3.9};
    box b3{1, 1.4, 3.9};

    std::cout << "test 1 (1) result: " << (b1==b2) << '\n';
    std::cout << "test 2 (0) result: " << (b1==b3) << '\n';
}

void test_box_less_than_operator() {
    box b1{1.4, 2.3, 3.9};
    box b2{2.3, 1.4, 3.9};
    box b3{1, 1.4, 3.9};
    box b4{3, 1.4, 3.9};
    
    std::cout << "test 1 (0) result: " << (b1<b2) << '\n';
    std::cout << "test 2 (0) result: " << (b2<b3) << '\n';
    std::cout << "test 3 (1) result: " << (b2<b4) << '\n';
}

void test_boxes_to_string() {
    std::vector<box> b_arr = {
        box{1.4, 2.3, 3.9},
        box{2.3, 1.4, 3.9},
        box{1, 1.4, 3.9},
        box{3, 1.4, 3.9}
    };
    
    boxes boxes;
    
    for(auto it = b_arr.begin(); it != b_arr.end(); ++it){
        boxes.add_box(*it);
    }
    
    std::cout << boxes.to_string() << '\n';
}

void test_boxes_to_string_sorted() {
    std::vector<box> b_arr = {
        box{1.4, 2.3, 3.9},
        box{2.3, 1.4, 3.9},
        box{1, 1.4, 3.9},
        box{3, 1.4, 3.9}
    };
    
    boxes boxes;
    
    for(auto it = b_arr.begin(); it != b_arr.end(); ++it){
        boxes.add_box(*it);
    }
    
    std::cout << boxes.to_string_sorted() << '\n';
    std::cout << boxes.to_string() << '\n';
}
