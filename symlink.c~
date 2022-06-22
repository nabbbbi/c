#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

static const char error [] = "Can't create directory";
static const char message [] = "New directory is created and deleted!";

int main()
{
  int n;
  n =mkdir("/home/pi/new_dir",0777);
  n =rmdir("/home/pi/new_dir");
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
