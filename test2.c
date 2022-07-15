#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

enum {size_of_queue = 16};
enum {port1 = 1024, port2 = 1025};
char *message = "hello";
char buf[10];

int main()
{
  int ok, ls,cls,cl;
  socklen_t len;
  struct sockaddr_in addr;
  ls = socket(AF_INET, SOCK_STREAM,0);
  if(ls == -1)
    {
      perror("socket");
      return 1;
    }
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port1);
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  ok = bind(ls,(struct sockaddr*)&addr, sizeof(addr));
  if(ok == -1)
    {
      perror("bind");
      return 1;
    }
  listen(ls, size_of_queue);
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
  write(cl, message, sizeof(message));
  read(cls,buf,sizeof(buf));
  write(1, buf, sizeof(buf));
  write(1,"\n",1);
  return 0;
}


