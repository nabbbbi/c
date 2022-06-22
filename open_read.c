#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

static const char error [] = "I don't know";
char buf[100];

int main()
{
  int n,r;
  n = open("/home/pi/test/some.txt",O_RDONLY);
  if(n<0)
    {
      write(1,error,sizeof(error));
      return 1;
    }
  r = read(n,buf,sizeof(buf));
  if(r<0)
    {
      write(2,error,sizeof(error));
      return 2;
    }
  printf("%s\n",buf);
  return 0;
}
