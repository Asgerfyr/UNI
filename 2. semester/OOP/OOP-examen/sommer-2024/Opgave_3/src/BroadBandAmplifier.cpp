//Opgave 3 d)
#include "BroadBandAmplifier.h"

BroadBandAmplifier::BroadBandAmplifier(
    double amplification):
    amplification(amplification){}


void BroadBandAmplifier::amplify(Signal &signal){
    for(auto it = signal.signalComponents.begin(); it != signal.signalComponents.end(); ++it){
        (*it).amplify(amplification);
    }
}