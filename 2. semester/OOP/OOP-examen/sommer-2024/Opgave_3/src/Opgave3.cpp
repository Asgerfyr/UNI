#include "BroadBandAmplifier.h"
#include "NarrowBandAmplifier.h"
#include <iostream>


int main()
{
	//Opgave 3 f-1)
	Signal signal;
	signal.addComponent(2,1000,0);
	signal.addComponent(4,2000,0);
	signal.addComponent(6,3000,0);
	signal.addComponent(8,4000,0);

	std::cout << "signals:" << '\n';
	std::cout << signal.toString() << '\n';
	
	//Opgave 3 f-2)
	
	BroadBandAmplifier bamp{2};
	NarrowBandAmplifier namp{10,3500,2500};
	
	std::cout << "bamp:" << '\n';
	bamp.amplify(signal);
	std::cout << signal.toString() << '\n';
	
	std::cout << "namp:" << '\n';
	namp.amplify(signal);
	std::cout << signal.toString() << '\n';
	
	return 0;
}
