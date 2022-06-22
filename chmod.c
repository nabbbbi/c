#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

static const char error [] = "Can't change rights";
static const char message [] = "Rights will be changed!";

int main()
{
  int n;
  n =chmod("/home/pi/test/some1.txt",0777);
  if(n<0) 
    {
      write(1,error,sizeof(error));
      write(n,"\n",1);
      return 1;
    }
  write(1,message,sizeof(message));
  write(n,"\n",1);
  return 0;
}
