#ifndef __POT__
#define __POT__

class Pot {
public:
    Pot();
    int getValue();
private:
    void readValue();
    int value;
};

#endif