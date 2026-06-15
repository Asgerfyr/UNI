#include "SignalComponent.h"

SignalComponent::SignalComponent(double amplitude, double frequency, double phase): amplitude_(amplitude),
	frequency_(frequency), phase_(phase)
{
}

double SignalComponent::get_amplitude() const
{
	return amplitude_;
}

double SignalComponent::get_frequency() const
{
	return frequency_;
}

void SignalComponent::amplify(const double amplification)
{
	amplitude_*=amplification;
}

std::string SignalComponent::to_string() const
{
	return "Amplitude:" + std::to_string(amplitude_) + " Frequency:" + std::to_string(frequency_) + " Phase:" +
		std::to_string(phase_);
}
