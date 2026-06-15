#pragma once
#include <string>

class SignalComponent
{
public:
	SignalComponent(double amplitude, double frequency, double phase);
	void amplify(double amplification);
	double get_amplitude() const;
	double get_frequency() const;
	std::string to_string() const;

private:
	double amplitude_;
	double frequency_;
	double phase_;
};
