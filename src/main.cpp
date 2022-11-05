
//Dependencies
#include <Arduino.h>
#include "DriveTrain.h"
#include "FSM.h"

RobotState currentState = start; //Set Initial State to Start on Upload
DriveTrain Robot(1,2,3,4,5,6,8,9,10,11); //Very messed up code but don't have enough time

//Arduino Setup
void setup() {
  Serial.begin(9600); //Setup Serial Port
   //Setup Robot Object with Motor1A,Motor1B,Motor2A,Motor2B, and EN pin.
}

//Loop
void loop() {
  finiteStateMachine(currentState, Robot); //Start Finite State Machine
  delay(100);
}