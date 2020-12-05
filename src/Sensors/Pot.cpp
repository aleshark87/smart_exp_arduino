#include "Sensors/Pot.h"

Pot::Pot(){
}

void Pot::readValue(){
    this->value = map(analogRead(potPIN), 0, 1023, 1, 51);
}

int Pot::getValue(){
    readValue();
    return this->value;
}