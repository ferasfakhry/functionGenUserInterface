#ifndef FUNCTIONGENERATOR_H
#define FUNCTIONGENERATOR_H

#include <visainstrument.h>

class FunctionGenerator : public VisaInstrument
{
    float freq;
public:
    FunctionGenerator();
    void sweep(float,float);

    void setVoltage(float);

    void setFrequency(float);
    void applySquareWave(float);
    void applySinWave(float);
    void applyRamp(float);
    void applyPulse(float);
    void applyPhase(float);
    void applyOffset(float);
};

#endif // FUNCTIONGENERATOR_H
