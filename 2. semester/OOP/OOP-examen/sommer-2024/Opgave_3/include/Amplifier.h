#pragma once
#include "Signal.h"
//Opgave 3 a)
class Amplifier
{
public:
    virtual void amplify(Signal &signal) = 0;
};
