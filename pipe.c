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
  pipe(fd); /* at the beginning chanel will be open if parent process. */
  p1 = fork(); /*child #1 will inherint input and output parent's channel*/
  if (p1 == 0)
    {
      /*child #1*/
      close(fd[0]); /*we close input of parent's chanel. and take care of output to bound with
		      2nd child's input*/
      /*...*/
      write(fd[1],message,sizeof(message) -1); /*sent message along chanel to 2nd child*/
      /*...*/
      exit(0);
    }
  p2 = fork(); /*second child is born*/
  if (p2 == 0)
    {
      /* child #2 */
      int rc;
      close(fd[1]); /* close output of channel. this child now can only receive message from 
		      another end of channel e.d. child #2 */
      /*...*/
      rc = read(fd[0], buf, sizeof(buf)); /*get message from child #1 and put it to buffer*/
      /*...*/
      if(rc < 0)
	{
	  write(2,error,sizeof(error)-1); 
	  return 1;
	}x
      exit(0);
    }
  /*parent proccess*/
  close(fd[1]);
  close(fd[2]);
  /*...*/
  return 0;
}
