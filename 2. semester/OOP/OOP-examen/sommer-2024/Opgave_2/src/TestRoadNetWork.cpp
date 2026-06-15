#include "TestRoadNetWork.h"
#include <iostream>
#include "RoadNetwork.h"

void test_road_network()
{
	const Location l11(1, 1);
	const Location l12(1, 2);
	const Location l21(2, 1);
	const Location l22(2, 2);

	RoadNetwork road_network;
	road_network.addNode(l11);
	road_network.addNode(l12);
	road_network.addNode(l21);
	road_network.addNode(l22);


	//Self connection not allowed
	try
	{
		road_network.addConnection(l11, l11);
	}
	catch (std::invalid_argument& e)
	{
		std::cout << e.what() << '\n';
	}

	//(1,1)-(2,2)
	road_network.addConnection(l11, l22);

	//Connection is already established
	try
	{
		road_network.addConnection(l22, l11);
	}
	catch (std::invalid_argument& e)
	{
		std::cout << e.what() << '\n';
	}

	//(1,1)-(1,2)
	road_network.addConnection(l11, l12);

	//(1,1)-(2,1)
	road_network.addConnection(l11, l21);

	const auto neighbours = road_network.getAllNeighbours(l11);
	std::cout << "Number of neighbours " << neighbours.size() << '\n';
}
