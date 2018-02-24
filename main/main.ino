#import "maze.h"
#import "movement.h"
#import "globals.h"

void setup() {
  // put your setup code here, to run once:
  Maze_T maze = init();
  Movement_T movement = movement_init();
  int coord1 = 0, coord2 = 0, d = -1;
}

void loop() {
  // put your main code here, to run repeatedly:
  if (((coord1 == 7) || (coord1 == 8)) && ((coord2 == 7) || (coord2 == 8))) {
    //???
  }
  d = getDirection(maze, coord1, coord2);
  move_square(d);
  if (d == NORTH) {coord2++;}
  if (d == EAST) {coord1++;}
  if (d == SOUTH) {coord2--;}
  if (d == WEST) {coord1--;}
  updatePosition(maze, coord1, coord2);
}
