#include "Fraction.h"
#include <iostream>
#include <stdexcept>


int main()
{
	//Opgave 1 c-1)
	std::cout << "test1:" << '\n';
	Fraction f1{1,1};
	std::cout << "nominator:" << f1.getNominator() << '\n';	
	std::cout << "denominator:" << f1.getDenominator() << '\n';	
	std::cout << '\n';
	
	
	
	//Opgave 1 c-2)
	std::cout << "test2:" << '\n';
	try{
		Fraction f2{1,0};
	}catch (const std::exception &ex) {
		std::cerr << ex.what() << '\n';
	} 
	std::cout << '\n';
	
	
	//Opgave 1 c-3)
	std::cout << "test3:" << '\n';
	Fraction frac_1{3,2}, frac_2{9,6}, frac_3{1,2};
	std::cout << "frac1 == frac2 == " << ((frac_1 == frac_2)?"true":"false") << '\n';	
	std::cout << "frac1 == frac3 == " << ((frac_1 == frac_3)?"true":"false") << '\n';	
	std::cout << '\n';
	
	
	//Opgave 1 e)
	std::cout << "test4:" << '\n';
	Fraction f3{2,3};
	std::cout << f3 << '\n';
	std::cout << '\n';
	
	
	//Opgave 1 g)
	std::cout << "test5:" << '\n';
	Fraction fr1{1,2},fr2{1,3};
	std::cout << "fr1: " << fr1 << '\n';
	std::cout << "fr2: " << fr2 << '\n';
	Fraction fr3 = fr1 + fr2;
	std::cout << "fr3 = fr1 + fr2 = 5/6: " << fr3 << '\n';
	std::cout << '\n';
	
	return 0;
}
