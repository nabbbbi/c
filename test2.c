#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <signal.h>

void handler()
{
  printf("signal 'CTRL+C' received!\n");
}

char buf[150];

int main()
{
  fd_set input;
  int result, len;
  struct timeval t;
  signal(SIGINT, handler);
  for(;;)
    {
      FD_ZERO(&input);
      FD_SET(0, &input);
      t.tv_sec=3;
      t.tv_usec=500000;
      result = select(FD_SETSIZE, &input,NULL, NULL, &t);
      switch(result){
      case(-1):
	if (errno = EINTR)
	  {
	    printf("signal is received\n");
	    return 0;
	  }
	perror("select");
	exit(1);
      case(0):
      printf("timeout(-3.5s) -_-\n");
      break;
      default:
	if(FD_ISSET(0, &input))
	  {
	    ioctl(0, FIONREAD,&len);
	    if(len ==0)
	      {
		printf("keyboard donen. EOF\n"); /* we received eof signal */
		exit(0);
	      }
	    buf[len]=0;
	    read(0,buf,len);
	    printf("%s",buf);
	  }
	break;
      }
    }
  return 0;
}
  
