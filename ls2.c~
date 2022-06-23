#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>


static const char error [] = "ERROR";
int main()
{
  int pid,status;
  pid=fork();
  if(pid == 0)
    {
      int fd = open("flist",O_CREAT | O_WRONLY | O_TRUNC, 0666);
      if(fd == -1)
	{
	  perror("flist");
	  exit(1);
	}
      dup2(fd,1);
      close(fd);
      execlp("ls","ls","-l","-a","-R","/",NULL);
      perror("ls");
      exit(1);
    }
  /*Parent proccess*/
  wait(&status);
  if (!WIFEXITED(status) || WEXITSTATUS(status)!=0)
  {
    write(1,error,sizeof(error));
    return 2;
  } 
  return 0;
}
