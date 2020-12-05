#ifndef __BUFFER__
#define __BUFFER__

extern float sonarSpeed;
extern float sonarValue;
extern float sonarAcc;
enum State{START, SLEEP, ERROR, EXPERIMENT, END};
extern State state;

#endif
