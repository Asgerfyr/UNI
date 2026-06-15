#pragma once
#include "Amplifier.h"

//Opgave 3 b)
class BroadBandAmplifier : public Amplifier  
{
public:
    BroadBandAmplifier(double amplification);
    void amplify(Signal &signal) override;
    
private:
    double amplification;
};

