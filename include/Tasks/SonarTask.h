#ifndef __SONARTASK__
#define __SONARTASK__

#include "Task.h"
#include "../Sensors/Sonar.h"
#define LIBCALL_ENABLEINTERRUPT
#include <EnableInterrupt.h>
#define MAX_TIME 20000

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
