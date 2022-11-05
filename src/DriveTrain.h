#include <Arduino.h>

class DriveTrain{
  public:
    int A,B,C,D,EN1,EN2;
    int speed = 100;
    void driveForward();
    void driveBackward();
    void setDifferential(int Difference);
    void setSpeed(int NewSpeed);
    DriveTrain(int A, int B, int C, int D, int EN1, int EN2){
      A = A;
      B = B;
      C = C;
      D = D;
      EN1 = EN1;
      EN2 = EN2;
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

void DriveTrain::driveBackward(){
  Serial.println("Driving Backward");
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
}


void DriveTrain::setDifferential(){
  Serial.println("Driving Differential");

}

void DriveTrain::setSpeed(int NewSpeed){
  Serial.println("Setting Speed");
  speed = NewSpeed;
  analogWrite(EN1, speed);
  analogWrite(EN2, speed);
}
