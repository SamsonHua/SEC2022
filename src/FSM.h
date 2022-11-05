//Finite State Machine Handler to handle Robot States
//By using a state machine handler, we are able to be safe
//Within the context of robotics, as well as handle modular code
//Made by Samson H.

#include <Arduino.h> //Should be an ifndef here but forgot how to do those

enum RobotState{
  start, //This is the starting state of the robot when booting up
  estop, //This is the emergency stop state, robot will stop
  lineFollowTime, //Go straight for a certain time interval
  lineFollowUntilStop, //Go until a single light trigger
  turnLeft, //Turn Right For Predefined Time
  turnRight,
  turnFlip, //Turn Left For Predfined Time
};

void finiteStateMachine(RobotState &currentState, DriveTrain &robot, RobotState &last_state, int tableNumber){
  switch (currentState){
    case start:
        if(0){
            Serial.println("[RemyBot] WAITING FOR SWITCH...");
            robot.setLEDState("waiting");
        }else{
            Serial.println("[RemyBot] Starting next phase");
            currentState = lineFollowUntilStop;
        }
      
    break;

    case estop:
      Serial.println("[RemyBot] E-STOP DETECTED... STOPPING NOW");
      robot.setLEDState("estop");
      robot.estop();
      
    break;

    case lineFollowTime:
      Serial.println("[RemyBot] LINE FOLLOWING STARTED..");
      robot.followLineTime();
      robot.setLEDState("go");
    break;

    case lineFollowUntilStop:
      Serial.println("[RemyBot] LINE FOLLOWING STARTED..");
      robot.setLEDState("go");
      if(robot.status != 0){
        robot.followLineUntil();
      }else{
        if(tableNumber > 5){
            currentState = turnRight;
        }else if (tableNumber < 5){
            currentState = turnLeft;

        }else{
            currentState = lineFollowTime;

        }
      }
    break;

    case turnLeft:
      Serial.println("[RemyBot] Turning Left..");
      robot.setLEDState("turning");
      robot.turn(1);
      currentState=estop;

    break;

    case turnRight:
      Serial.println("[RemyBot] Turning Right..");
      robot.setLEDState("turning");
      robot.turn(0);
      currentState=estop;

    break;

    case turnFlip:
      Serial.println("[RemyBot] Turning Right..");
      robot.setLEDState("turning");
      robot.turn(0);

    break;
  }
}