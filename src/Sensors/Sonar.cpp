#include "Sensors/Sonar.h"

Sonar::Sonar(int triggerPin, int echoPin){
    this->termo = new Termo();
    vs = 331.45 + 0.62*(termo->getValue());
    this->triggerPin = triggerPin;
    this->echoPin = echoPin;
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void Sonar::readValue(){
    /* invio impulso */
    digitalWrite(triggerPin,LOW);
    delayMicroseconds(5);
    digitalWrite(triggerPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin,LOW);
    
    /* ricevi l’eco */
    float tUS = pulseIn(echoPin, HIGH);
    float t = tUS / 1000.0 / 1000.0 / 2;
    float d = t*vs;
    this->value = d;
}

float Sonar::getValue(){
    readValue();
    return this->value;
}

bool Sonar::objectPresent(){
    readValue();
    return (this->value < MAXDISTANCE);
}
