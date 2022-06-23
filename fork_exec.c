#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  int pid;
  pid = fork();
  if (pid == -1) /*error while creating the proccess*/
    {
      perror("fork");
      exit(1);
    }
  if (pid == 0) /*bourn proccess*/
    {
      execlp("ls","-l","-a","/var",NULL);
      perror("ls"); /*exec return steering that means error*/
      exit(1); /*end proccess with error-code*/
    }
  /*parent proccess*/
  wait(NULL); /*waiting until ending bourn proccess and at the same time
		take of zombie*/
  printf("Ok\n");
  return 0;
}
