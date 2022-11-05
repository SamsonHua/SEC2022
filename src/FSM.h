//Finite State Machine Handler to handle Robot States
//By using a state machine handler, we are able to be safe
//Within the context of robotics, as well as handle modular code
//Made by Samson H.

#include <Arduino.h> //Should be an ifndef here but forgot how to do those

enum RobotState{
  start, //This is the starting state of the robot 
  estop, //This is the emergency stop state, robot will stop
  lineFollowTime, //Go straight for a certain time interval
  lineFollowUntilBoth, //Go until a double light trigger
  lineFollowUntilStop, //Go until a single light trigger
  turnLeft, //Turn Right For Predefined Time
  turnRight,
  turnFlip, //Turn Left For Predfined Time
};

void finiteStateMachine(RobotState &currentState, DriveTrain &robot, RobotState &last_state){
  switch (currentState){
    case start:
        if(robot.status==3){
            Serial.println("[RemyBot] WAITING FOR SWITCH...");
            robot.setLEDState("waiting");
        }else{
            Serial.println("[RemyBot] Starting next phase");
            currentState = lineFollowUntilBoth;
        }
      
    break;

    case estop:
      Serial.println("[RemyBot] E-STOP DETECTED... STOPPING NOW");
      robot.setLEDState("estop");
      robot.estop();
      
    break;

    case lineFollowTime:
      Serial.println("[RemyBot] LINE FOLLOWING STARTED..");
      robot.followLine();
      robot.setLEDState("go");
    break;

    case lineFollowUntilStop:
      Serial.println("[RemyBot] LINE FOLLOWING STARTED..");
      robot.followLine();
      robot.setLEDState("go");
    break;

    case lineFollowUntilBoth:
      Serial.println("[RemyBot] LINE FOLLOWING STARTED..");
      robot.followLine();
      robot.setLEDState("go");
    break;

    case turnLeft:
      Serial.println("[RemyBot] Turning Left..");
      robot.setLEDState("turning");
      robot.turn(1);

    break;

    case turnRight:
      Serial.println("[RemyBot] Turning Right..");
      robot.setLEDState("turning");
      robot.turn(0);

    break;

    case turnFlip:
      Serial.println("[RemyBot] Turning Right..");
      robot.setLEDState("turning");
      robot.turn(0);

    break;
  }
}