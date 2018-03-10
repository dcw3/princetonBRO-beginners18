#include "encoders_simple.h"
//#include "globals.h" - Already included and needed in 

const int motorPinOA = 6;
const int motorPinOB = 7;
const int motorPinTA = 8;
const int motorPinTB = 9;
//const int NORTH = 1;
//const int SOUTH = 2;
//const int WEST = 2;
//const int EAST = 2;

const int intervalSwitch = 5000; //ms change direction
const int intervalRead = 2500; //ms to read

bool straight = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPinOA, OUTPUT);
  pinMode(motorPinOB, OUTPUT);
  pinMode(motorPinTA, OUTPUT);
  pinMode(motorPinTB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int time = millis();
  if (time % intervalRead == 0) {
    String left = "Left Distance " + String(getCumulDist(WEST));
    Serial.println(left);
    String right = "North Distance " + String(getCumulDist(NORTH));
    Serial.println(right);
  }
  if (time % intervalSwitch == 0) {
    straight = !straight;
  }
  if (straight) {
    digitalWrite(motorPinOA, HIGH);
    digitalWrite(motorPinOB, LOW);
    digitalWrite(motorPinTA, HIGH);
    digitalWrite(motorPinTB, LOW);
  } else {
    digitalWrite(motorPinOA, LOW);
    digitalWrite(motorPinOB, HIGH);
    digitalWrite(motorPinTA, LOW);
    digitalWrite(motorPinTB, HIGH);
  }
}
