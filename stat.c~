#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

static const char error [] = "Can't change rights";
static const char message [] = "change own rigts";

int main()
{
  int n;
  n =chown("/home/pi/test/some1.txt",1000,1000); /*works with file that refers
						   symlink*/
  n =lchown("/home/pi/test/some1.txt",1000,1000); /*works with symlink*/
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
