#include "pid.h"
#include "stdio.h"

#define HEIGHT 100
#define WIDTH  2

int main(void)
{
  FILE *myfile;
  double mypos;
  double time;
  double value;
  int i;
  int j;
  struct PID* pid;
  pid = init(1,0.11,0.11);
  setPoint(pid, 20);
  myfile=fopen("decreasing.tsv", "r");
  for(i = 0; i < HEIGHT; i++)
  {
    for (j = 0 ; j < WIDTH; j++)
    {
    	if(j == 0) {
        	fscanf(myfile,"%lf",&mypos);
        	//printf("%.15f ",mypos);
    	}
        else if(j==1) {
        	fscanf(myfile,"%lf",&time);
        	//printf("%.15f ",time);
        	//printf("\n");
        }
    }
    update(pid,mypos,time);
    value = getVal(pid);
    printf("%.15f ",value);//printf("\n");
    printf("\n");

  }
  reset(pid);
  fclose(myfile);
}