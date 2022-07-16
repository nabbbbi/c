#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include "pointer_rsln.h"
#include <errno.h>

char *msg = "HELLO!";
char *error = "we have got signal!";
char *time_out = "time is out!";

int main()
{
  int clients[10];
  int connected[10];
  socklen_t len;
  int i, ok_7, flags;
  int ls;
  struct sockaddr_in addr,addrls;
  int port = 1024, portls;
  /* create clients */
  for(i=0; i < 10; i++)
    {
      clients[i] = socket(AF_INET, SOCK_STREAM, 0);
      flags = fcntl(clients[i],F_GETFL);
      fcntl(clients[i], F_SETFL, flags | O_NONBLOCK);
      addr.sin_family = AF_INET;
      addr.sin_port = htons(port++);
      addr.sin_addr.s_addr = htonl(INADDR_ANY);
      ok_7 = bind(clients[i],(struct sockaddr*)&addr, sizeof(addr));
      if (ok_7 == -1)
	{
	  perror("bind");
	  break;
	}
    }
  /* done creating clients */
  ls = socket(AF_INET, SOCK_STREAM, 0);
  addrls.sin_family = AF_INET;
  portls = port++;
  addrls.sin_port = htons(portls);
  addrls.sin_addr.s_addr = htonl(INADDR_ANY);
  ok_7 = bind(ls, (struct sockaddr*)&addrls, sizeof(addr));
  if(ok_7 == -1)
    {
      perror("bind");
      return 1;
    }
  for(;;)
    {
      int fd, res;
      fd_set readfds, writefds;
      struct timeval timeout;
      int max_d = ls;
      FD_ZERO(&readfds); /* repeal readfds */
      FD_ZERO(&writefds); /* repeal writefds */
      FD_SET(ls, &readfds); /* add fd to readfds domain */
      /* make cycle that run through each sockets */
      for(fd = clients[1]; fd < sizeof(clients); fd++)
	{
	  /* fd - is eack fd of client */
	  FD_SET(fd, &readfds);
	  if(write(fd, msg, sizeof(msg)))
	    FD_SET(fd, &writefds);
	  if (fd > max_d)
	    max_d = fd;
	}
      timeout.tv_sec = 1;
      timeout.tv_usec = 300000; 
      res = select(max_d + 1, &readfds, &writefds, NULL, &timeout);
      if(res == -1)
	{
	  if(errno = EINTR)
	    {
	      write(2, error, sizeof(error));
	      return 1;
	    }
	  else
	    {
	      perror("select");
	      return 1;
	    }
	  continue; 
	}
      if (res == 0)
	{
	  write(2, time_out, sizeof(time_out));
	  continue;
	}
      /* works with only listen socket */
      if (FD_ISSET(ls, &readfds))
	{
	  len = sizeof(addr);
	  connected[1] = accept(ls, (struct sockaddr*)&addr, &len);
	  flags = fcntl(connected[1],F_GETFL);
	  fcntl(connected[1], F_SETFL, flags | O_NONBLOCK);
	}
    }
  return 0;
}


