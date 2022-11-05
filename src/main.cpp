
//Dependencies
#include <Arduino.h>
#include "DriveTrain.h"
#include "FSM.h"

RobotState currentState = state1;

//Arduino Setup
void setup() {
  Serial.begin(9600); //Setup Serial Port
  DriveTrain Robot(1,2,3,4,5,6); //Setup Robot Object with Motor1A,Motor1B,Motor2A,Motor2B, and EN pin.
}

//Loop
void loop() {
  finiteStateMachine(currentState);
}