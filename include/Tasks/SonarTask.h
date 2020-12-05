#ifndef __SONARTASK__
#define __SONARTASK__

#include "Task.h"
#include "../Sensors/Sonar.h"
#include "Arduino.h"
#include "Buffer.h"
#include "Definitions.h"
#define LIBCALL_ENABLEINTERRUPT
#include <EnableInterrupt.h>

class SonarTask: public Task {
private:
    Sonar* sonar;
    int period;
    int periodSum;
    public:
    SonarTask();
    void init(int period);
    void tick();
};

#endif
