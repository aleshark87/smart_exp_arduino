#include "Tasks/SerialTask.h"

SerialTask::SerialTask(){}

void SerialTask::init(int period){
    Task::init(period);
}

static void sendMsgState(){
    String str = "state/" + String(state);
    Serial.println(str); Serial.flush();
}

void SerialTask::tick(){
    if(state == START){
        sendMsgState();
    }
    if(state == EXPERIMENT){
        String str = "state/" + String(state) + "!speed/" + String(abs(round(sonarSpeed*100)));
        str += "/pos/" + String(round(sonarValue*100));
        str += "/acc/" + String(abs(round(sonarAcc*100)));
        Serial.println(str); Serial.flush();
    }
    if(state == END){
        sendMsgState();
    }
}