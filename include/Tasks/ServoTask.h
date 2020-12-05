#ifndef __SERVOTASK__
#define __SERVOTASK__

#include "Arduino.h"
#include "Task.h"
#include <Servo.h>
#include "Buffer.h"
#include "Definitions.h"

class ServoTask : public Task{
private:
    Servo myservo;
    int period;
public:
    ServoTask();
    void init(int period);
    void tick();
};

#endif 
