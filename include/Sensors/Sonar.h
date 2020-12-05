#ifndef __SONAR__
#define __SONAR__

#include "Termo.h"

class Sonar {
public:
    Sonar(int triggerPin, int echoPin);
    float getValue();
    bool objectPresent();
private:
    Termo* termo;
    void readValue();
    int triggerPin;
    int echoPin;
    float value;
};

#endif