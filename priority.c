#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main()
{
  int pid, p;
  pid = fork();
  nice(3); /*reduce priority*/
  p= getpriority(PRIO_PROCESS,pid); /*RPIO USER is alt*/
  p= setpriority(PRIO_PROCESS,pid,10);
  printf("%d\n",p);
  return 0; 
}
