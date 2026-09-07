#include "test_1.h"
#include <iostream>
#include "matrix_1.h"

void test_to_string() {
    matrix_1 m(4, 2);
    m.set(1, 1, 1);
    m.set(1, 2, 1);
    m.set(2, 1, 1);
    m.set(2, 2, 2);
    m.set(3, 1, 8);
    m.set(3, 2, 9);
    m.set(4, 1, 11);
    m.set(4, 2, 12);
    std::cout << m.to_string() << "\n\n";
}


void test_add() {
    matrix_1 m1(2, 2);
    m1.set(1, 1, 1);
    m1.set(1, 2, 2);
    m1.set(2, 1, 3);
    m1.set(2, 2, 4);
    
    matrix_1 eye(2, 2);
    eye.set(1, 1, 1);
    eye.set(1, 2, 0);
    eye.set(2, 1, 0);
    eye.set(2, 2, 1);

    std::cout << "matrix 1:" << '\n';
    std::cout << m1.to_string() << "\n\n";

    std::cout << "eye matrix:" << '\n';
    std::cout << eye.to_string() << "\n\n";
    
    std::cout << "added = " << "\n";
    matrix_1 added = m1+eye;
    
    std::cout << added.to_string() << "\n\n";

}

void test_stream() {
    matrix_1 m1(2, 2);
    m1.set(1, 1, 1);
    m1.set(1, 2, 2);
    m1.set(2, 1, 3);
    m1.set(2, 2, 4);
    
    matrix_1 eye(2, 2);
    eye.set(1, 1, 1);
    eye.set(1, 2, 0);
    eye.set(2, 1, 0);
    eye.set(2, 2, 1);

    std::cout << "matrix 1:" << '\n';
    std::cout << m1 << "\n\n";

    std::cout << "eye matrix:" << '\n';
    std::cout << eye << "\n\n";
}

void test_exception() {
    matrix_1 m1(2, 2);
    m1.set(1, 1, 1);
    m1.set(1, 2, 2);
    m1.set(2, 1, 3);
    m1.set(2, 2, 4);

    try
    {
        std::cout << "try set invalit row 0" << '\n';
        m1.set(0,1,5);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << '\n';
    
    try
    {
        std::cout << "try set invalit colum 3" << '\n';
        m1.set(1,3,5);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << '\n';
    
    try
    {
        std::cout << "try get invalit row 4" << '\n';
        std::cout << m1.get(4,1) << '\n'; 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << '\n';
    
    try
    {
        std::cout << "try get invalit colum 0" << '\n';
        std::cout << m1.get(1,0) << '\n'; 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    


}
