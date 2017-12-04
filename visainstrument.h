#ifndef VISAINSTRUMENT_H
#define VISAINSTRUMENT_H

#include <visa.h>

class VisaInstrument
{
protected:
    ViSession session;
    ViSession defaultRM;
    ViStatus status;
    ViFindList fList;
    ViUInt32 numInst;
    ViChar desc[VI_FIND_BUFLEN];
    ViChar resultBuffer[256];
    ViUInt32 resultCount;

public:
    VisaInstrument();

    virtual void idn();
    void initialization();
};

#endif // VISAINSTRUMENT_H
