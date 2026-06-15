#pragma once

//Opgave 2 a)

#include <vector>
#include <stdexcept>

template<typename T>
class Network {
public:
	void addNode(const T&);
	void addConnection(const T&, const T&);
	std::vector<T> getAllNeighbours(const T&) const;
	

private:
	const T* findNode(const T&) const;
	std::vector<T> nodes_;
	std::vector<std::pair<const T*, const T*>> connections_;
};

template<typename T>
void Network<T>::addConnection(const T& first, const T& second)
{
	const T* first_p = findNode(first);
	const T* second_p = findNode(second);

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

template<typename T>
std::vector<T> Network<T>::getAllNeighbours(const T& location) const
{
	const auto node_p = findNode(location);

	std::vector<T> neighbours;

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

template<typename T>
//Ignore the problems with == on doubles
const T* Network<T>::findNode(const T& to_find) const
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

template<typename T>
void Network<T>::addNode(const T& location)
{
	nodes_.push_back(location);
}
