#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

static const char error [] = "I don't know";
static const char message [] = "message message message";

int main()
{
  int n,m;
  n = open("/home/pi/test/some.txt",O_WRONLY | O_APPEND);
  if(n<0)
    {
      write(1,error,sizeof(error));
      return 1;
    }
  m = write(n,message,sizeof(message));
  if(m<0)
    {
      write(2,error,sizeof(error));
      return 2;
    }
  printf("%d\n",m);
  write(n,"\n",1);
  return 0;
}
