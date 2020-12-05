#ifndef __POT__
#define __POT__

#include "Arduino.h"
#include "Headers/Definitions.h"

class Pot {
public:
    Pot();
    int getValue();
private:
    void readValue();
    int value;
};

#endif