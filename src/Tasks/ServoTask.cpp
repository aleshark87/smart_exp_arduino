#include "Tasks/ServoTask.h"

ServoTask::ServoTask(){
    myservo.attach(servoPIN);
}

void ServoTask::init(int period){
    this->period = period;
    Task::init(period);
}

void ServoTask::tick(){
    if(state == EXPERIMENT){
        int absSpeed = abs(sonarSpeed) * 100 * 2 ;
        myservo.write(absSpeed); 
    }
    else{
        myservo.write(0);
    }
}