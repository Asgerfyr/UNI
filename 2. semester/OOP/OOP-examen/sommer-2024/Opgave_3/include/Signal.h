#pragma once
#include <string>
#include <vector>
#include "SignalComponent.h"
class Signal
{
public:
	void addComponent(double amplitude, double frequency, double phase);
	std::string toString() const;
	std::vector<SignalComponent> signalComponents;
};
