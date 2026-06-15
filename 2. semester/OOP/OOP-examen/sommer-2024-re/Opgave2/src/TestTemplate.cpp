#include "polynomialTemplate.h"
#include <iostream>

void testTemplate()
{
	//Opgave 2 b)
	PolynomialTemplate<int> p1({1, 2, 3, 4});
	PolynomialTemplate<int> p2({10, -20, 30, 40, 50});
	std::cout << p1(10) << "\n";
	std::cout << p2(10) << "\n";
	std::cout << (p1 + p2).toString() << "\n";
}
