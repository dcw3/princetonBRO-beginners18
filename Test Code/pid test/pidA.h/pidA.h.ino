#include "globals.h"
void setup() {
  // return a PID loop object
struct PID {
  double kP ,kI, kD;
  double integral;
  double setPoint;
  double derivative;
  double prevError;
  bool isFirstUpdate;
};
}
typedef struct PID *PID_T;
PID_T init(double kP, double kI, double kD) {
  struct PID *p;
  p->kP = kP;
  p->kI = kI;
  p->kD = kD;
  p->integral = 0;
  p->setPoint = 0;
  p->derivative = 0;
  p->prevError = 0;
  p->isFirstUpdate = true;
  return p;
}
void loop() {
}
