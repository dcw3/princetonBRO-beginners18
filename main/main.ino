#ifndef MAIN2_H_INCLUDED
#define MAIN2_H_INCLUDED

#import "maze.h"
#import "movement.h"
#import "globals.h"

void setup() {
  // put your setup code here, to run once:
  Maze_T maze = maze_init();
  Movement_T movement = movement_init();
  //int coord1 = 0, coord2 = 0,
  d = -1;
  int centerFound = 0;
}
void loop() {
  // put your main code here, to run repeatedly:

  if (((GetCoord1() == 7) || (GetCoord2() == 8)) && ((GetCoord1() == 7) || (GetCoord2() == 8))) {
  //implement back-trace
    centerFound = 1;
    while ((GetCoord1() != 0)&&(GetCoord2() != 0)){
        d = ReturnToOtherCheckpoint(maze, GetCoord1(), GetCoord2());
        moved(d);
        //updatePosition(maze, GetCoord1(), GetCoord2());

    }
  }
  if (centerFound = 0){
    d = getDirection(maze, GetCoord1(), GetCoord2());
    moved(d);
    updatePosition(maze, GetCoord1(), GetCoord2());
  }

  if (centerFound = 1){
        d = ReturnToOtherCheckpoint(maze, GetCoord1(), GetCoord2());
        moved(d);
  }


#endif // MAIN2_H_INCLUDED
