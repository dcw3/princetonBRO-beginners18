#ifndef MAIN2_H_INCLUDED
#define MAIN2_H_INCLUDED

#import "maze.h"
#import "movement.h"
#import "globals.h"

void setup() {
  // put your setup code here, to run once:
  Maze_T maze = init();
  Movement_T movement = movement_init();
  int coord1 = 0, c oord2 = 0, d = -1;
}
void loop() {
  // put your main code here, to run repeatedly:

  if (((coord1 == 7) || (coord1 == 8)) && ((coord2 == 7) || (coord2 == 8))) {
  //implement back-trace
    while ((coord1 != 0)&&(coord2 != 0){
        d = getDirection(maze, coord1, coord2);
        moved(d);
        updatePosition(maze, GetCoord1(), GetCoord1());
    }
  }

  d = getDirection(maze, coord1, coord2);
  moved(d);
  updatePosition(maze, GetCoord1(), GetCoord1());


#endif // MAIN2_H_INCLUDED
