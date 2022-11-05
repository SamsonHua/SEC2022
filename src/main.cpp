
//Dependencies
#include <Arduino.h>
#include "DriveTrain.h"
#include "FSM.h"

int TargetTable = 6;

RobotState currentState = start; //Set Initial State to Start on Upload
RobotState lastState;
DriveTrain Robot(2,3,5,4,9,10,11,12,13,7); //Very messed up code but don't have enough time

//Arduino Setup
void setup() {
  Serial.begin(9600); //Setup Serial Port
   //Setup Robot Object with Motor1A,Motor1B,Motor2A,Motor2B, and EN pin.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

//Loop
void loop() {
  finiteStateMachine(currentState, Robot, lastState, TargetTable); //Start Finite State Machine
  delay(100);
}