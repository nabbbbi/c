#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

static const char error [] = "Can't rename";
static const char message [] = "File is renamed!";

int main()
{
  int n;
  n =rename("/home/pi/test/some.txt","/home/pi/test/some1.txt");
  /*if newpath file exists, oldpath file swap it superfast. almost deleting*/
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
