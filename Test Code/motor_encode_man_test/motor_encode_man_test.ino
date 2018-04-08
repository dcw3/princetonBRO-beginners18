#include "encoders_simple.h"
//#include "globals.h" - Already included and needed in 

const int motorPinOA = 6;
const int motorPinOB = 7;
const int motorPinTA = 8;
const int motorPinTB = 9;

const int intervalSwitch = 5000; //ms change direction
const int intervalRead = 2500; //ms to read

bool straight = true;
int currentLeft = 0;
int currentUp = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int test = getCumulDist(NORTH);
  if (currentUp != test) {
    Serial.println("Up: " + String(test));
    currentUp = test;
  }
  test = getCumulDist(WEST);
  if (currentLeft != test) {
    Serial.println("Up: " + String(test));
    currentLeft = test;
  }
}
