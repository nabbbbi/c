#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

static const char error [] = "Truncating didn't work";
static const char message [] = "Truncate the file after 100 byte";

int main()
{
  int n,m;
  n = truncate("/home/pi/test/pers2.txt",100);
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
  close(n);
  return 0;
}
