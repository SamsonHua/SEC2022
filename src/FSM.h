//Finite State Machine Handler to handle Robot States
//By using a state machine handler, we are able to be safe
//Within the context of robotics, as well as handle modular code
//Made by Samson H.

#include <Arduino.h> //Should be an ifndef here but forgot how to do those

enum RobotState{
  start, //This is the starting state of the robot 
  estop, //This is the emergency stop state, robot will stop
  lineFollow, //To be done
};
void finiteStateMachine(RobotState &currentState, DriveTrain &robot){
  switch (currentState){
    case start:
        if(0){
            Serial.println("[RemyBot] WAITING FOR SWITCH...");
            robot.setLEDState("waiting");
        }else{
            Serial.println("[RemyBot] Starting next phase");
            currentState = lineFollow;
        }
      
    break;

    case estop:
      Serial.println("[RemyBot] E-STOP DETECTED... STOPPING NOW");
      robot.setLEDState("estop");
      robot.estop();
      
    break;

    case lineFollow:
      Serial.println("[RemyBot] LINE FOLLOWING STARTED..");
      robot.followLine();
    break;
  }
}