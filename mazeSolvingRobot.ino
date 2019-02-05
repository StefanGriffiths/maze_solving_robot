#include <Servo.h>
#include "Action.h"

//Left Motor
#define ENA 5 //controls speed
//control motion of left motor
#define IN1 7
#define IN2 8

//Right Motor
#define ENB 6 //controls speed
//control motion of right motor
#define IN3 9
#define IN4 11

#define forwardSpeed 200
#define turnSpeed 200
#define backSpeed 200

//pins for the ultrasonic sensor
#define trigPin A5
#define echoPin A4

float frontDuration, leftDuration, rightDuration;
float frontDistance, leftDistance, rightDistance;
float maxDistance = 20;

Servo myServo;


void setup() {
  Serial.begin(9600);
  //Motors 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  //Ultrasonic Sensors
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(3);
}

int checkLeftDistance(){
  myServo.write(180);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(4);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  leftDuration = pulseIn(echoPin, HIGH);
  leftDistance = leftDuration * (0.034 / 2);
  return leftDistance;
}

int checkRightDistance(){
  myServo.write(0);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(4);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  rightDuration = pulseIn(echoPin, HIGH);
  rightDistance = rightDuration * (0.034 / 2);
  return rightDistance;
}

int checkForwardDistance(){
  myServo.write(90);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(4);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  frontDuration = pulseIn(echoPin, HIGH);
  frontDistance = frontDuration * (0.034 / 2);
  return frontDistance;
}

void stop(){
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
}

void moveForward(){
  analogWrite(ENA, forwardSpeed);
  analogWrite(ENB, forwardSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void moveBackward(){
  analogWrite(ENA, backSpeed);
  analogWrite(ENB, backSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveRight(){
  analogWrite(ENA, turnSpeed);
  analogWrite(ENB, turnSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveLeft(){
  analogWrite(ENA, turnSpeed);
  analogWrite(ENB, turnSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void loop() {
  //check the forward distance
  checkForwardDistance();
  frontDistance = checkForwardDistance();
  if(frontDistance < maxDistance)
  {
    stop();
    checkLeftDistance();
    leftDistance = checkLeftDistance();
    delay(1000);
    checkRightDistance();
    rightDistance = checkRightDistance();
    delay(1000);

    if(leftDistance < rightDistance)
    {
      moveRight();
    }
    else if(leftDistance > rightDistance)
    {
      moveLeft();
    }
  }
  else 
  {
    moveForward();
  }
}
  //if forwardDistance is less than MaxFrontDistance
    //object is too close
    //check the left distance 
    //check the right distance 
      //if the left distance is less than the right distance 
        //move right
      //else if left distance more than right distance 
        //move left 
   //otherwise move fowards
