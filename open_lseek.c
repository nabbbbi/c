#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

static const char error1 [] = "can't open file1";
static const char error2 [] = "can't open file2";
static const char error3 [] = "can't open file3";
char buf[100];

int main()
{
  int n,m,l;
  n = open("/home/pi/test/pers2.txt",O_RDONLY);
  if(n<0)
    {
      write(1,error1,sizeof(error1));
      return 1;
    }
  l=lseek(n,-100,SEEK_END);
  if(l<0)
    {
      write(1,error2,sizeof(error2));
      return 2;
    }
  m = read(n,buf,sizeof(buf));
  if(m<0)
    {
      write(1,error3,sizeof(error3));
      return 3;
    }
  printf("%s\n",buf);
  close(n);
  return 0;
}
