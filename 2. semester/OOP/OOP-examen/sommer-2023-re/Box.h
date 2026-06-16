#pragma once

#include "Resistor.h"

class Box
{
public:
	Box(int size = 5);
	~Box();

	void addResistor(const Resistor& r);
	void print() const;

private:
	Resistor* resistors_;
	int size_;
	int noOfResistors_;
};

