#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

static const char error[] = "can't open\n";
char buf[50];

int main ()
{
  mkfifo("/home/pi/fifo", 0777);  
  if (fork() == 0) /* create proccess for cmd ls -lR */
    {
      int fd1;
      fd1 = open("/home/pi/fifo",O_WRONLY | O_NONBLOCK);
      if (fd1 < 0)
	{
	  write(1,error,sizeof(error) - 1);
	  exit(1);
	}
      dup2(fd1,1); /* std output = to chanel */
      close(fd1); /* fd[1] no need anymore */
      execlp("ls", "ls", "-lR", NULL); /* launch ls -lR */
      perror("ls"); /* if don't work tell about error */
      exit(1); 
    }
  if (fork() == 0)  /* proccess for grep  */
    {
      int fd0;
      fd0 = open("/home/pi/fifo", O_RDONLY | O_NONBLOCK);
      if (fd0 < 0)
	{
	  write(1,error,sizeof(error) -1 );
	  exit(0);
	}
      dup2(fd0,0); /* std input - from chanel */
      close(fd0); /* fd[0] no need anymore */
      execlp("grep", "grep", "^d", NULL); /* launch grep  */
      perror("grep"); /* if we can't lauch, tell about error */
      exit(1);
    }
  
  /* in parent proccess close both ends of chanel*/
  wait(NULL); /* wait tell to parent that child proccess is ended */
  wait(NULL);
  
  /*...*/
  return 0;
}
