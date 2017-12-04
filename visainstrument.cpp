#include "visainstrument.h"
#include <visa.h>
#include <windows.h>

VisaInstrument::VisaInstrument()
{

}

void VisaInstrument::idn()
{
    status = viPrintf(session, "*IDN?");

}

void VisaInstrument::initialization()
{
    status=viOpenDefaultRM(&defaultRM);

    //if(status != VI_SUCCESS) return EXIT_FAILURE;

    status=viFindRsrc(defaultRM,"USB0::0x0400::0x09C4::DG1D182403417::INSTR", &fList,&numInst,desc);
    Sleep(5000);

    status=viOpen(defaultRM,desc,VI_NULL,VI_NULL,&session);
    Sleep(5000);

    status = viPrintf(session,(const char*)"*IDN?",5,VI_NULL );
    Sleep(5000);

    status = viRead(session, (unsigned char*)resultBuffer, 256, &resultCount);
    //read response of Instrument
    Sleep(5000);
    //printf("Found instrument :%s \n",resultBuffer);
}

