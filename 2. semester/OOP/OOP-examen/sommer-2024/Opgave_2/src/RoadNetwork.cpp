#include "RoadNetwork.h"
#include <stdexcept>


void RoadNetwork::addConnection(const Location& first, const Location& second)
{
	const Location* first_p = findNode(first);
	const Location* second_p = findNode(second);

	if (first_p == nullptr || second_p == nullptr)
	{
		throw std::invalid_argument("Node does not exist");
	}

	if (first == second)
	{
		throw std::invalid_argument("Self connection not allowed");
	}
	for (const auto& connection : connections_)
	{
		if (connection.first == first_p && connection.second == second_p || connection.first == second_p && connection.second
			== first_p)
		{
			throw std::invalid_argument("Connection is already established");
		}
	}
	connections_.emplace_back(first_p, second_p);
}

std::vector<Location> RoadNetwork::getAllNeighbours(const Location& location) const
{
	const auto node_p = findNode(location);

	std::vector<Location> neighbours;

	for (const auto& connection : connections_)
	{
		if (node_p == connection.first)
		{
			neighbours.push_back(*connection.second);
		}
		if (node_p == connection.second)
		{
			neighbours.push_back(*connection.first);
		}
	}
	return neighbours;
}

//Ignore the problems with == on doubles
const Location* RoadNetwork::findNode(const Location& to_find) const
{
	for (const auto& location : nodes_)
	{
		if (location == to_find)
		{
			return &location;
		}
	}
	return nullptr;
}

void RoadNetwork::addNode(const Location& location)
{
	nodes_.push_back(location);
}
