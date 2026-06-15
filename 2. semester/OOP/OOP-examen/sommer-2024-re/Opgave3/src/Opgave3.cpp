#include "ToUpperCase.h"
#include "ToLowerCase.h"
#include "RemoveChar.h"
#include "Document.h"
#include <iostream>

int main()
{
	// Opgave 3 h)
	ToUpperCase to_U;
	ToLowerCase to_L;
	RemoveChar rm_e{'e'};
	
	Document document_1{std::string("My First Test")}, 
			 document_2{std::string("My Second Test")};

	std::cout << "document 1:" << '\n';
	std::cout << document_1 << '\n';

	document_1.add(&rm_e);
	document_1.add(&to_U);

	document_1.process();
	
	std::cout << "document 1 after proc:" << '\n';
	std::cout << document_1 << '\n';
	
	std::cout << '\n';

	std::cout << "document 2" << '\n';
	std::cout << document_2 << '\n';
	document_2.add(&rm_e);
	document_2.add(&to_L);

	document_2.process();

	std::cout << "document 2 after proc:" << '\n';
	std::cout << document_2 << '\n';

	return 0;
}