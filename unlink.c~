#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

static const char error [] = "Can't creat hard link";
static const char message [] = "Hard link is created!";

int main()
{
  int n;
  n =link("/home/pi/test/some.txt","/home/pi/test/some_link");
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
