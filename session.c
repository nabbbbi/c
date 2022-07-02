#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n,m,pid;
  n = getsid(2192);
  m = getpgid(2192);
  printf("the session is: %d and group %d\n",n,m);
  pid = fork();
  if (pid > 0) /* kill parent proccess in order to to change own pid
		e.d. pid this program that you see and create new session
	       . To create new session pid should not be in any group
	       and session*/
    exit(0);
  setsid(); /*create new session*/
  return 0;
}

