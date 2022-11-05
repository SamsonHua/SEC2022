#include <Arduino.h>
enum RobotState{
  state1,
  state2,
  state3,
};

void finiteStateMachine(RobotState currentState){
  switch (currentState){
    case state1:
      Serial.println("State 1 has been initiated");
    break;

    case state2:
      Serial.println("State 2 has been initiated");
    break;

    case state3:
      Serial.println("State 3 has been initiated");
    break;
  }
}