#include "TPoint.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    TPoint<double> d_p{1.4,-2.6};
    TPoint<float> f_p{-1.4,2.6};
    TPoint<int> i_p{-1,-2};

    std::cout << "Double point:" << '\n';
    d_p.print();
    std::cout << '\n';
    std::cout << "kvadrant: " << d_p.beregnKvadrant() << '\n';
    std::cout << '\n';

    std::cout << "Float point:" << '\n';
    f_p.print();
    std::cout << '\n';
    std::cout << "kvadrant: " << f_p.beregnKvadrant() << '\n';
    std::cout << '\n';

    std::cout << "Int point:" << '\n';
    i_p.print();
    std::cout << '\n';
    std::cout << "kvadrant: " << i_p.beregnKvadrant() << '\n';
    std::cout << '\n';

    return 0;
}
