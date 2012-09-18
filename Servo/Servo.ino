#include <Servo.h>

Servo myservo;
int servoPin = 9; // Set this to the PIN connected to servo's control line
int val = 0;
int stepAngle = 1;
int interval = 10;
int minAngle = 0;
int maxAngle = 180;

void setup(){
  myservo.attach(servoPin);
}

void loop(){
  for(val=minAngle;val<=maxAngle;val+=stepAngle){
    myservo.write(val);
    delay(interval);
  }
  for(val=maxAngle;val>=minAngle;val-=stepAngle){
    myservo.write(val);
    delay(interval);
  }
}
