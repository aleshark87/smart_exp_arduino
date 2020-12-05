#include "Tasks/CoreTask.h"
#include <EnableInterrupt.h>

State state;
volatile bool btPressedV;
bool timerOn;
bool ledState = false;
bool ledStateError = false;

/* INT handler */
void btPressed(){
    btPressedV = true;
}

void wakeUp() {}

void timerFunction() {
    timerOn = true;
}

CoreTask::CoreTask(Task* sonarTask, Task* servoTask, Task* serialTask){
    this->sonarTask = sonarTask; this->servoTask = servoTask; this->serialTask = serialTask;
    this->periodSum = 0;
    this->pot = new Pot(); sonar = new Sonar(TRIGGER_PIN, ECHO_PIN);
}

void CoreTask::init(int period){
    state = START;
    this->period = period; Task::init(period); 
    timerOn = false; btPressedV = false; 
    this->periodSum = 0;
    analogWrite(GREEN_PIN, 255); analogWrite(RED_PIN, 0); 
    enableInterrupt(2, wakeUp, RISING);  
    enableInterrupt(BstartPIN, btPressed, RISING);
}

void CoreTask::tick(){
    if(state == START){
        /* No btn pression in SLEEP_TIME period */
        if(periodSum >= SLEEP_TIME){
            timerFunction();
        }
        if((timerOn == false) && (btPressedV == false)){
        }
        else{
            disableInterrupt(BstartPIN);
            if(btPressedV == true){
                if(sonar->objectPresent()){
                    disableInterrupt(BstartPIN); disableInterrupt(2);
                    /* Calculates new Period taking value from the pot */
                    int periodFromPot = pot->getValue() * 20;
                    sonarTask->init(periodFromPot); servoTask->init(periodFromPot);
                    serialTask->init(periodFromPot);
                    analogWrite(RED_PIN, 255); analogWrite(GREEN_PIN, 0);
                    state = EXPERIMENT; 
                }
                else{
                    state = ERROR;
                }
                
            }
            if(btPressedV == false){ 
                disableInterrupt(BstartPIN);
                state = SLEEP; 
            }
        }
        periodSum += period;
    }
    
    if(state == ERROR){
        analogWrite(GREEN_PIN, 0);
        String str = "state/" + String(state);
        Serial.println(str); Serial.flush();
        int timeStart = millis();
        while((millis() - timeStart) < ERROR_TIME){
            /* Blinking */
            if(!ledStateError){
                analogWrite(GREEN_PIN, 255);
            }
            else{
                analogWrite(GREEN_PIN, 0);
            }
            delay(30);ledStateError = !ledStateError;
        }
        this->init(this->period);
    }

    if(state == SLEEP){
        analogWrite(GREEN_PIN, 0); 
        String str = "state/" + String(state) + "s";
        Serial.print("state/"); Serial.print(state); Serial.print("\n"); Serial.flush();
        /* Going to sleep */
        set_sleep_mode(SLEEP_MODE_PWR_DOWN);
        sleep_enable();
        sleep_mode();
        /** The program will continue from here. **/ 
        /* First thing to do is disable sleep. */  
        sleep_disable();   
        disableInterrupt(pirSensorPin);
        this->init(this->period);
    }
    
    if(state == END){
        analogWrite(GREEN_PIN, 0);
        /* Receive Message */
        if (MsgService.isMsgAvailable()) {
            Msg* msg = MsgService.receiveMsg();    
            if (msg->getContent() == "OK"){
                this->init(this->period);
            }  
            /* NOT TO FORGET: message deallocation */
            delete msg;         
        }
        else{
            /* Blinking */
            if(!ledState){
                analogWrite(RED_PIN, 255);
            }
            else{
                analogWrite(RED_PIN, 0);
            }
            ledState = !ledState;
        }
    }
         
    
    }






