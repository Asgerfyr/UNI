#pragma once
#include <vector>
#include "Location.h"

class RoadNetwork
{
public:
	void addNode(const Location&);
	void addConnection(const Location&, const Location&);
	std::vector<Location> getAllNeighbours(const Location&) const;
	

private:
	const Location* findNode(const Location&) const;
	std::vector<Location> nodes_;
	std::vector<std::pair<const Location*, const Location*>> connections_;
};
