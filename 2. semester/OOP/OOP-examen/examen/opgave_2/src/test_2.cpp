#include "test_2.h"
#include "matrix_2.h"
#include <iostream>

void test_matrix() {
    matrix_2* m1 = new matrix_2{2,2};

    std::cout << "test set:" << '\n';
    std::cout << "making mathix:" << '\n';
    std::cout << "[1 2]" << '\n';
    std::cout << "[3 4]" << "\n\n";
    m1->set(1, 1, 1);
    m1->set(1, 2, 2);
    m1->set(2, 1, 3);
    m1->set(2, 2, 4);
    

    std::cout << "test get:" << '\n';
    std::cout << "get 1,2: " << m1->get(1, 2) << '\n';
    std::cout << "get 2,2: " << m1->get(2, 2) << '\n' << '\n';
    
    std::cout << "test to_string:" << '\n';
    std::cout << m1->to_string() << '\n';
    
    delete m1;
}
