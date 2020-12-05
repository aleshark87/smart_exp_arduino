#include "Sensors/Termo.h"
#include "Arduino.h"
#define RT0 10000   // Ω
#define B 3977      // K
#define VCC 5    //Supply voltage
#define R 10000  //R=10KΩ

Termo::Termo(int pin){
    this->pin = pin;
    RT = VR = ln = TX = T0 = VRT = 0;
    T0 = 25 + 273.15; //Temperature T0 from datasheet
}

void Termo::calculateValue(){
    VRT = (5.00 / 1023.00) * VRT;  //Conversion to voltage
    VR = VCC - VRT;
    RT = VRT / (VR / R);           //Resistance of RT

    ln = log(RT / RT0);
    TX = (1 / ((ln / B) + (1 / T0))); 
    //Temperature from thermistor

    TX = TX - 273.15;     //Conversion to Celsius

}

void Termo::readValue(){
    VRT = analogRead(pin);     //Acquisition analog value of VRT
}

float Termo::getValue(){
    readValue();
    calculateValue();
    return TX;
}

