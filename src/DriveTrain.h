//Not doing headers properly apologies
//This code is for the robot drive train
//Made by Samson H.

#include <Arduino.h>

class DriveTrain{
  public:
    enum Status{
      running, danger, done, idle
    };
    Status status = idle;
    int A,B,C,D,EN1,EN2,LS,RS,leftLed,rightLed;
    int speed = 60;
    int kp = 1;
    //Movement Functions
    void driveForward();
    void turn180();
    void estop();
    void turn(int direction);
    void stop();
    //Adjustment Functions
    void setDifferential(int Difference);
    void setSpeed(int NewSpeed);
    void setKp(int newKp);
    void setLEDState(String status);
    //Movement Functions
    void followLineUntil();
    void followLineTime();
    //Acquisition Functions
    int readSensorL();
    int readSensorR();

    //Constructor
    DriveTrain(int ANew, int BNew, int CNew, int DNew, int EN1New, int EN2New, int LS, int RS, int leftLed, int rightLed){
      A = ANew;
      B = BNew;
      C = CNew;
      D = DNew;
      EN1 = EN1New;
      EN2 = EN2New;
      LS = LS;
      RS = RS;
      leftLed = leftLed;
      rightLed = rightLed;
      Serial.println("Initialing Robot Drive Train...!");
      this->setSpeed(speed);
    }

};

void DriveTrain::driveForward(){
  Serial.println("Driving Forward");
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
}

void DriveTrain::stop(){
  Serial.println("Stopping");
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
}

void DriveTrain::turn180(){
  Serial.println("Driving 180");
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  delay(2000); //Hardcoded turning value
}

void DriveTrain::turn(int direction){
  if(direction==1){
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    delay(1000); //Hardcoded turning value
  }else{
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    delay(1000);
  }
}


void DriveTrain::setDifferential(int Difference){
  Serial.println("Driving Differential");
  analogWrite(EN1, speed + Difference);
  analogWrite(EN2, speed - Difference);
}

void DriveTrain::followLineUntil(){
  this->readSensorR();
  this->readSensorL();

  //Truth Table
  if(LS == HIGH && RS == HIGH){
    //Both Triggered
    this->stop();
    status = done;
  }else if(LS == HIGH && RS == LOW){
    //Left Triggered
    this->setDifferential(kp);
  }else if(LS == LOW && RS == HIGH){
    //RightTriggered
    this->setDifferential(-kp);
  }else{
    this->driveForward();
  }
}

void DriveTrain::followLineTime(){
  this->readSensorR();
  this->readSensorL();
  //Truth Table
  if(LS == HIGH && RS == HIGH){
    //Both Triggered
    this->stop();
  }else if(LS == HIGH && RS == LOW){
    //Left Triggered
    this->setDifferential(kp);
  }else if(LS == LOW && RS == HIGH){
    //RightTriggered
    this->setDifferential(-kp);
  }else{
    this->driveForward();
  }
}

void DriveTrain::setSpeed(int NewSpeed){
  Serial.println("Setting Speed");
  speed = NewSpeed;
  analogWrite(EN1, speed);
  analogWrite(EN2, speed);
}

void DriveTrain::setKp(int newKp){
  Serial.println("Setting Kp");
  kp = newKp;
}

int DriveTrain::readSensorL(){
  Serial.println("Retrieving Sensor Value");
  int Reading = digitalRead(LS);
  return Reading;
}

int DriveTrain::readSensorR(){
  Serial.println("Retrieving Sensor Value");
  int Reading = digitalRead(RS);
  return Reading;
}

void DriveTrain::estop(){
  Serial.println("ESTOP");
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
}

void DriveTrain::setLEDState(String newState){
    if(newState == "go"){
        digitalWrite(rightLed, LOW);
        digitalWrite(leftLed, HIGH);
        delay(50);
        digitalWrite(leftLed, LOW);
        delay(50);
    }else if(newState == "estop"){
        digitalWrite(leftLed, LOW);
        digitalWrite(rightLed, HIGH);
        delay(50);
        digitalWrite(rightLed, HIGH);
        delay(50);
    }else if(newState == "waiting"){
        digitalWrite(leftLed, HIGH);
        digitalWrite(rightLed, HIGH);

    }else if(newState == "turning"){
        digitalWrite(rightLed, HIGH);
        digitalWrite(leftLed, LOW);
        delay(50);
        digitalWrite(rightLed, LOW);
        digitalWrite(leftLed, HIGH);
        delay(50);
    }else{
        Serial.println("Fatal Error");
    }
}