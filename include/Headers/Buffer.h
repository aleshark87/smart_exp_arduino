#ifndef __BUFFER__
#define __BUFFER__

/** This header defines the global variables that program needs to work */

extern float sonarSpeed;
extern float sonarValue;
extern float sonarAcc;
enum State{START, SLEEP, ERROR, EXPERIMENT, END};
extern State state;

#endif
