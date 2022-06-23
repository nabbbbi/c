#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>


static const char error [] = "ERROR";
int main()
{
  int pid,status,fd;
  fd = open("flist",O_CREAT | O_WRONLY | O_TRUNC, 0666);
  if(fd == -1)
    {
      perror("flist");
      exit(1);
    }
  pid=fork();
  if(pid == -1)
    {
      write(1,error,sizeof(error));
      return 1;
    }
  if(pid == 0)
    {
      dup2(fd,1);
      close(fd);
      execlp("ls","ls","-l","-a","-R","/",NULL);
      perror("ls");
      exit(1);
    }
  /*parent proccess*/
  close(fd);
  wait(&status);
  /*  nfd = dup(fd);
      nfd = fcntl(fd, F_DUPFD, 0); The same thing*/
  /*fcntl(fd,F_DUPFD, 20) - create descriptor that cloning fd under value 20, if its free, vice versa find free descriptor that above than 20. 20 is hurdle*/
  return 0;
}
