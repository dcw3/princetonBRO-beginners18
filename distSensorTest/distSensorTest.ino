#include "distSensor_2.h"
void setup() {
  Serial.begin(9600);
}
void loop() {
  for(int i = 0; i < 4; i++) {
    Serial.print(getDist(i));
    Serial.print("\t");
  }
  Serial.println();
}
//#include <Wire.h>
//#include <VL6180X.h>
//
//VL6180X sensor;
//
//void setup() 
//{
//  Serial.begin(9600);
//  Wire.begin();
//  
//  sensor.init();
//  sensor.configureDefault();
//  sensor.setTimeout(500);
//}
//
//void loop() 
//{ 
//  Serial.print(sensor.readRangeSingleMillimeters());
//  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
//  
//  Serial.println();
//}
////#include "VL6180X.cpp"
////void setup() {
////  Serial.begin(9600);
////  VL6180X();
////  void configureDefault();
////  // put your setup code here, to run once:
////
////}
////
////void loop() {
////  // put your main code here, to run repeatedly:
////  delay(1000);
////  for(int j = 0; j < 4; j++) {
////    int dist = readReg(uint16_t reg);
////      Serial.println(dist);
////      Serial.print("\t");
////  }
////  Serial.println();
////}
