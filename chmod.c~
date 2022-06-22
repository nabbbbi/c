#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

static const char error [] = "Can't create symbol link";
static const char message [] = "Create symbol link!";

int main()
{
  int n;
  n =symlink("/home/pi/test/direct/","/home/pi/test/sym_direct");
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
