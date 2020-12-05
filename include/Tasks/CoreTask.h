#ifndef __CORETASK__
#define __CORETTASK__

#include "Task.h"
#include "Arduino.h"
#include "Headers/Buffer.h"
#include "Sensors/Pot.h"
#include "Sensors/Sonar.h"
#include "MsgService.h"
#include "Headers/Definitions.h"
#include <avr/sleep.h>

void timerFunction();
void btPressed();

class CoreTask : public Task {
private:
    Task* sonarTask;
    Task* servoTask;
    Task* serialTask;
    Sonar* sonar;
    Pot* pot;
    int period;
    int periodSum;
public:
    CoreTask(Task* sonarTask, Task* servoTask, Task* serialTask);
    void init(int period);
    void tick();
    
};

#endif