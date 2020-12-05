#ifndef __TERMO__
#define __TERMO__

#include "Headers/Definitions.h"
#include "Arduino.h"

class Termo {
public:
    Termo();
    float getValue();
private:
    float RT, VR, ln, TX, T0, VRT;
    void readValue();
    void calculateValue();
};

#endif