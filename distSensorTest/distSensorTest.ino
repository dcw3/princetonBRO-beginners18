#include "distSensors.h"
void setup() {
  setupSensors();
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  for(int j = 0; j < 4; j++) {
      Serial.println(getDist(j));
      Serial.print("\t");
  }
  Serial.println();
}
