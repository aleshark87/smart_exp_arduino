#include <Arduino.h>
#include "Tasks/CoreTask.h"
#include "Scheduler.h"
#include "Tasks/ServoTask.h"
#include "Tasks/SonarTask.h"
#include "Tasks/SerialTask.h"
#include "Headers/Definitions.h"

Scheduler sched;

void setup(){
  /* scheduler and serial initialize */
  Serial.begin(9600);
  sched.init(20);

  pinMode(pirSensorPin, INPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BstartPIN, INPUT_PULLUP);
  pinMode(BstopPIN, INPUT_PULLUP);
  pinMode(potPIN, INPUT);
  
  Task* sonarTask = new SonarTask();
  Task* servoTask = new ServoTask();
  Task* serialTask = new SerialTask();
  Task* coreTask = new CoreTask(sonarTask, servoTask, serialTask);

  serialTask->init(200);
  coreTask->init(200);
  sonarTask->init(200);
  sonarTask->init(200);
  /* add task to the scheduler */
  sched.addTask(serialTask);
  sched.addTask(coreTask);
  sched.addTask(sonarTask);
  sched.addTask(servoTask);
}

void loop(){
  /* only needs to do this */
  sched.schedule();
  
}

