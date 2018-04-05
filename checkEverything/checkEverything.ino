#include "maze.h"
void setup() {
  // put your setup code here, to run once:
  setupSensors();
  Maze_T maze = init_maze();
  Movement_T movement = init_movement();
  Serial.begin(9600);
}
void loop() {
  //move in a square and print encoder cumul distance
  printDistances();
  for(int i = 0; i < 4; i++) {
    moved(i, 500);
  }
  printDistances();
  //===================================================
  //move back and forth
  int startDist = (getCumulDist(NORTH));
  Serial.println(getCumulDist(NORTH));
  moved(SOUTH, 500);
  Serial.println(getCumulDist(NORTH)-startDist);
  moved(NORTH, 500);
  Serial.println(getCumulDist(NORTH)-startDist);
 }

void printDistances() {
  Serial.print("Encoder Cumulative Distance: ");
  for(int i = 0; i < 4; i++) {
      Serial.println(getCumulDist(i));
      Serial.print("\t");
  }
  Serial.println();
  Serial.print("Distance values: ");
  for(int j = 0; j < 4; j++) {
      Serial.println(getDist(j));
      Serial.print("\t");
  }
  Serial.println();
}

