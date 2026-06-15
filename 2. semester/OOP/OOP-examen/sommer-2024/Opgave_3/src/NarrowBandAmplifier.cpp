//Opgave 3 e)
#include "NarrowBandAmplifier.h"

NarrowBandAmplifier::NarrowBandAmplifier(
    double amplification, 
    double upperFrequencyLimit, 
    double lowerFrequencyLimit):
    amplification(amplification), 
    upperFrequencyLimit(upperFrequencyLimit), 
    lowerFrequencyLimit(lowerFrequencyLimit){}


void NarrowBandAmplifier::amplify(Signal &signal){
    for(auto it = signal.signalComponents.begin(); it != signal.signalComponents.end(); ++it){
        if((*it).get_frequency() < lowerFrequencyLimit || 
        (*it).get_frequency() > upperFrequencyLimit) continue;
        
        (*it).amplify(amplification);
    }
}
