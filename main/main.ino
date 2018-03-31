#ifndef MAIN2_H_INCLUDED
#define MAIN2_H_INCLUDED

#import "maze.h"
#import "movement.h"
#import "globals.h"

void setup() {
  // put your setup code here, to run once:
  setupSensors();
  Maze_T maze = maze_init();
  Movement_T movement = movement_init();
  //int coord1 = 0, coord2 = 0,
  int d = -1;
  int centerFound = 0;

}
void loop() {
  // put your main code here, to run repeatedly:

  if (((GetCoord1() == 7) || (GetCoord1() == 8)) && ((GetCoord2() == 7) || (GetCoord2() == 8))) {
  //implement back-trace
    centerFound = 1;
    WillYouPleaseReturnForGodsSake();
  }
  if (centerFound = 0){
    d = getDirection(maze, GetCoord1(), GetCoord2());
    moved(d);
    updatePosition(maze, GetCoord1(), GetCoord2());
  }

  if (centerFound = 1){
        WillYouPleaseReturnForGodsSake();
  }
}

void WillYouPleaseReturnForGodsSake(){
  StackArray <int> x_stack_new;
  StackArray <int> y_stack_new;
  
    while ((GetCoord1() != 0)&&(GetCoord2() != 0)){
        x_stack_new.push(GetCoord1());
        x_stack_new.push(GetCoord2());
        d = ReturnToOtherCheckpoint(maze, GetCoord1(), GetCoord2());
        moved(d);
    }

    maze->x_stack = x_stack_new;
    maze->y_stack = y_stack_new;
}


#endif // MAIN2_H_INCLUDED
