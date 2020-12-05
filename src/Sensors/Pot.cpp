#include "Sensors/Pot.h"

Pot::Pot(){
}

/* The value of the pot is mapped in 50 values */
void Pot::readValue(){
    this->value = map(analogRead(potPIN), 0, 1023, 1, 51);
}

int Pot::getValue(){
    readValue();
    return this->value;
}