#include <Servo.h>

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
#define leftSpeed 200
#define rightSpeed 200
#define backSpeed 200

//pins for the ultrasonic sensor
const int trigPin = A5;
const int echoPin = A4;

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  stop();
}

void loop() {
  // put your main code here, to run repeatedly:
  moveForward();
  delay(1000);
  stop();
  delay(1000);
  moveBackward();
  delay(1000);
  moveRight();
  delay(1000);
  moveLeft();
  delay(1000);
  moveForward();
  delay(1000);
  moveBackward();
  delay(1000);
  stop();
  delay(1000);
}

void checkLeftDistance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(4);
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
  analogWrite(ENA, rightSpeed);
  analogWrite(ENB, rightSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveLeft(){
  analogWrite(ENA, leftSpeed);
  analogWrite(ENB, leftSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
