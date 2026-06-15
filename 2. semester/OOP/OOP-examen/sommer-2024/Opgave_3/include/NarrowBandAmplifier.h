#pragma once
#include "Amplifier.h"


//Opgave 3 c)
class NarrowBandAmplifier : public Amplifier
{
public:
    NarrowBandAmplifier(double amplification, double upperFrequencyLimit, double lowerFrequencyLimit);
    void amplify(Signal &signal) override;
private:
    double amplification;
    double upperFrequencyLimit;
    double lowerFrequencyLimit;
};