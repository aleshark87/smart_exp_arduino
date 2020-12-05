#ifndef __TERMO__
#define __TERMO__

class Termo {
public:
    Termo(int pin);
    float getValue();
private:
    float RT, VR, ln, TX, T0, VRT;
    void readValue();
    void calculateValue();
    int pin;
};

#endif