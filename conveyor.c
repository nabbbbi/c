#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>


char buf[50];

int main ()
{
  int fd[2];
  pipe(fd); /* make chanel for connection */
  if (fork() == 0) /* create proccess for cmd ls -lR */
    {
      close(fd[0]); /* no need to read from chanel */
      dup2(fd[1],1); /* std output = to chanel */
      close(fd[1]); /* fd[1] no need anymore */
      execlp("ls", "ls", "-lR", NULL); /* launch ls -lR */
      perror("ls"); /* if don't work tell about error */
      exit(1); 
    }
  if (fork() == 0)  /* proccess for grep  */
    {
      close(fd[1]); /* shouldn't write to chanel  */
      dup2(fd[0],0); /* std input - from chanel */
      close(fd[0]); /* fd[0] no need anymore */
      execlp("grep", "grep", "^d", NULL); /* launch grep  */
      perror("grep"); /* if we can't lauch, tell about error */
      exit(1);
    }
  
  /* in parent proccess close both ends of chanel*/
  
  close(fd[0]);
  close(fd[1]);
  wait(NULL); /* wait tell to parent that child proccess is ended */
  wait(NULL);
  
  /*...*/
  return 0;
}
