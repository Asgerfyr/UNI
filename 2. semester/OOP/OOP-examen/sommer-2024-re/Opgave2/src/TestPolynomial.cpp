#include "TestPolynomial.h"

#include <iostream>

#include "Polynomial.h"

void testPolynomial()
{
	Polynomial p1({1, 2, 3, 4});
	Polynomial p2({10, -20, 30, 40, 50});
	std::cout << p1(10) << "\n";
	std::cout << p2(10) << "\n";
	std::cout << (p1 + p2).toString() << "\n";
}
