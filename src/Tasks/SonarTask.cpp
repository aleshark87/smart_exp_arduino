#include "Tasks/SonarTask.h"

float sonarValue;
float prevSonarValue;
float sonarSpeed;
float prevSonarSpeed;
float sonarAcc;
int sonarPeriod;
volatile boolean pression;

//INT handler
void buttonPressed(){
    pression = true;
}

SonarTask::SonarTask(){
    this->period = 0.0;
    sonarPeriod = 0; pression = false;
    sonar = new Sonar(TRIGGER_PIN, ECHO_PIN);
}

void SonarTask::init(int period){
    periodSum = 0;
    this->period = period;
    Task::init(period);
    sonarValue = 0;
    enableInterrupt(BstopPIN, buttonPressed, RISING); pression = false;
}

void SonarTask::tick(){
    if(state == EXPERIMENT){
        if(periodSum < MAX_TIME && pression == false){
            prevSonarValue = sonarValue;
            sonarValue = sonar->getValue();
            prevSonarSpeed = sonarSpeed;
            sonarSpeed = (sonarValue - prevSonarValue) / ((float)period / 1000.0);
            sonarAcc = (sonarSpeed - prevSonarSpeed) / ((float)period / 1000.0);
        }
        else{
            disableInterrupt(BstopPIN);
            state = END;
        }
        periodSum += period;
    }
}