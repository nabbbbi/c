#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

static const char message[] = "Hi, brother!\n";
static const char error[] = "Can't open!\n";
char buf[50];
 
int main ()
{
  int fd[2];
  int p1,p2;
  pipe(fd);
  p1 = fork();
  if (p1 == 0)
    {
      /*child #1*/
      close(fd[0]);
      /*...*/
      write(fd[1],message,sizeof(message) -1);
      /*...*/
      exit(0);
    }
  p2 = fork();
  if (p2 == 0)
    {
      /* child #2 */
      int rc;
      close(fd[1]);
      /*...*/
      rc = read(fd[0], buf, sizeof(buf));
      /*...*/
      if(rc < 0)
	{
	  write(2,error,sizeof(error)-1);
	  return 1;
	}
      exit(0);
    }
  /*parent proccess*/
  close(fd[1]);
  close(fd[2]);
  /*...*/
  return 0;
}
