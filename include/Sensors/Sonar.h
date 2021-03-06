#ifndef __SONAR__
#define __SONAR__

#include "Termo.h"
#include "Headers/Definitions.h"
#include "Arduino.h"
#include "Headers/Buffer.h"

class Sonar {
public:
    Sonar(int triggerPin, int echoPin);
    float getValue();
    bool objectPresent();
private:
    float vs;
    Termo* termo;
    void readValue();
    int triggerPin;
    int echoPin;
    float value;
};

#endif