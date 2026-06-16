#include "Matrix2.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Matrix2 eye{}, m1{6,4,2,8};
    std::cout << "eye: " << eye << '\n';
    std::cout << "m1: " << m1 << '\n';

    std::cout << "m1*eye: " << (m1*eye) << '\n';

    return 0;
}
