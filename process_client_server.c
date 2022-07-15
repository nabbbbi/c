#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

enum {size_of_queue = 16};
enum {port1 = 1024, port2 = 1025};
char *message = "hello";
char buf[10];
volatile sig_atomic_t child_ready;
void handler(int n)
{
  signal(SIGUSR1, handler);
  child_ready = 1;
}

int main()
{
  int ok, ls,cls,cl, opt;
  int child_ready = 0;
  socklen_t len;
  struct sockaddr_in addr;
  /* signal(SIGUSR1, handler); */
  ls = socket(AF_INET, SOCK_STREAM,0);
  if(ls == -1)
    {
      perror("socket");
      return 1;
    }
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port1);
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  opt = 1;
  setsockopt(ls, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
  ok = bind(ls,(struct sockaddr*)&addr, sizeof(addr));
  if(ok == -1)
    {
      perror("bind");
      return 1;
    }
  listen(ls, size_of_queue);
  for(;;)
    {
      int pid;
      cl = socket(AF_INET, SOCK_STREAM,0);
      if (cl == -1)
	{
	  perror("socket");
	  return 1;
	}
      ok = connect(cl,(struct sockaddr*)&addr, sizeof(addr));
      if (ok == -1)
	{
	  perror("connect");
	  return 1;
	}
      len = sizeof(addr);
      cls = accept(ls,(struct sockaddr*)&addr,&len);
      if (cls == -1)
	{
	  perror("accept");
	  return 1;
	}
      pid = fork();
      if(pid == 0)
	{
	  /* child process */
	  close(ls);
	  write(cl, message, sizeof(message));
	  read(cls,buf,sizeof(buf));
	  write(1, buf, sizeof(buf));
	  write(1,"\n",1);
	  kill(getppid(),SIGUSR1);
	  exit(0);
	}
      /* parent process */
      while(!child_ready)
	pause();
      close(cls);
      do
	{
	  pid = wait4(-1, NULL, WNOHANG, NULL);
	} while (pid > 0);
    }
  shutdown(cl, SHUT_WR);
  close(cl);
  shutdown(cls,SHUT_RD);
  close(cls);
  shutdown(ls, SHUT_RD);
  close(ls);
  return 0;
}


