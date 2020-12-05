#ifndef __SERIALTASK__
#define __SERIALTASK__

#include "Headers/Buffer.h"
#include <Arduino.h>
#include "Task.h"
#include <math.h>

class SerialTask : public Task {
public:
    SerialTask();
    //20 default ?
    void init(int period);
    void tick();
};

#endif