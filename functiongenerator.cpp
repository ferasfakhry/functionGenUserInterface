#include <functiongenerator.h>
#include <../visa.h>
#include <stdio.h>
#include <windows.h>


FunctionGenerator::FunctionGenerator() : VisaInstrument()
{
    freq = 20000;
}
//put time variable in
     void FunctionGenerator::sweep(float StartFreq,float EndFreq)
     {
         char commandString[128];
//change this to sweep function
         sprintf(commandString, "SWE:STAT ON");
    viWrite(session, (unsigned char*)commandString, sizeof commandString, VI_NULL);
    Sleep(5000);
         sprintf(commandString, "FREQ:STAR MIN %f", StartFreq);
         viWrite(session, (unsigned char*)commandString, sizeof commandString, VI_NULL);
         Sleep(5000);
         viPrintf(session, commandString);
         Sleep(5000);
char commandString1[128];
         sprintf(commandString1, "FREQ:STOP MAX %f", EndFreq);
         viWrite(session, (unsigned char*)commandString1, sizeof commandString1, VI_NULL);
         sprintf(commandString, "SWE:TIME %f", 5.);
    viWrite(session, (unsigned char*)commandString, sizeof commandString, VI_NULL);
         Sleep(5000);
         viPrintf(session, commandString1);
         sprintf(commandString, "SWE:STAT Off");
    viWrite(session, (unsigned char*)commandString, sizeof commandString, VI_NULL);

     }
//APPL:SQU

     void FunctionGenerator::applyPhase(float phase)
     {
         char commandString[128];
         sprintf(commandString, "PHAS %f", phase);
         viWrite(session, (unsigned char*)commandString, sizeof commandString, VI_NULL);
         Sleep(5000);
         viPrintf(session, commandString);
         Sleep(5000);
     }
     void FunctionGenerator::applyOffset(float voltage)
     {
         char commandString[128];
         sprintf(commandString, "VOLT:OFFS %f", voltage);
         viWrite(session, (unsigned char*)commandString, sizeof commandString, VI_NULL);
         Sleep(5000);
         viPrintf(session, commandString);
         Sleep(5000);
     }

     void FunctionGenerator::applySquareWave(float frequency)
     {
         char commandString[128];
         sprintf(commandString, "APPL:SQU %f", frequency);
         viWrite(session, (unsigned char*)commandString, sizeof commandString, VI_NULL);
         Sleep(5000);
         viPrintf(session, commandString);
         Sleep(5000);
     }

     void FunctionGenerator::applySinWave(float frequency)
     {
         char commandString[128];
         sprintf(commandString, "APPL:SIN %f", frequency);
         viWrite(session, (unsigned char*)commandString, sizeof commandString, VI_NULL);
         Sleep(5000);
         viPrintf(session, commandString);
         Sleep(5000);
     }
     void FunctionGenerator::applyRamp(float frequency)
     {
         char commandString[128];
         sprintf(commandString, "APPL:RAMP %f", frequency);
         viWrite(session, (unsigned char*)commandString, sizeof commandString, VI_NULL);
         Sleep(5000);
         viPrintf(session, commandString);
         Sleep(5000);
     }
     void FunctionGenerator::applyPulse(float frequency)
     {
         char commandString[128];
         sprintf(commandString, "APPL:PULS %f", frequency);
         viWrite(session, (unsigned char*)commandString, sizeof commandString, VI_NULL);
         Sleep(5000);
         viPrintf(session, commandString);
         Sleep(5000);
     }
     void FunctionGenerator::setFrequency(float frequency)
     {
         char commandString[128];
         sprintf(commandString, "FREQ %f", frequency);
         viWrite(session, (unsigned char*)commandString, sizeof commandString, VI_NULL);
         Sleep(5000);
         viPrintf(session, commandString);
         Sleep(5000);
     }

     void FunctionGenerator::setVoltage(float volt)
     {
          char commandString[128];

         sprintf(commandString, "VOLT %f", volt);

         viWrite(session, (unsigned char*)commandString, sizeof commandString, VI_NULL);
     }
