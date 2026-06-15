#include "Amount.h"
#include <iostream>

int main()
{
	//Opgave 1 a)
	Currency dollar{std::string("dollar"),0.92};

	std::cout << dollar.fromStandardCurrency(460) << '\n';
	
	std::cout << dollar.toStandardCurrency(460) << '\n';

	//Opgave 1 e)

	Amount amt(100,dollar);
	std::cout << amt.toString() << '\n';
	
	
	//Opgave 1 g)
	Currency pound{std::string("pound"),1.18};
	Amount amt1(1000,dollar), amt2(1000,pound);
	
	std::cout << (amt1 + amt2).toString() << '\n';
	
	
	
	
	//Opgave 1 i)
	Amount amt_1(500,dollar), amt_2(389.83,pound);
	
	std::cout << ((amt_1 == amt_2)?"true":"false") << '\n';
	

	return 0;
}
