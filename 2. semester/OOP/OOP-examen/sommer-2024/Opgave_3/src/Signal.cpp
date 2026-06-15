#include "Signal.h"
void Signal::addComponent(double amplitude, double frequency, double phase)
{
	signalComponents.emplace_back(amplitude, frequency, phase);
}



std::string Signal::toString() const
{
	std::string result;
	for (const auto& component : signalComponents)
	{
		result.append(component.to_string());
		result.append("\n");
	}
	return result;
}
