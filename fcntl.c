#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

static const char error [] = "I don't know";
enum {true = 1, false = 0};

int main()
{
  int n,flags;
  n = open("/home/pi/test/some.txt",O_WRONLY | O_APPEND);
  if(n<0)
    {
      write(1,error,sizeof(error));
      return 1;
    }
  flags=fcntl(n,F_GETFL); /*fcntl can change flags for descriptors*/
  if(flags & O_WRONLY) /*if not match will be 0, if match will be non zero*/
    printf("%d\n",true);
  fcntl(n,F_SETFL, flags | O_NONBLOCK); /*set NONBLOCK flag with SETFL*/
  fcntl(4, F_SETFL, O_NONBLOCK); /*same thing as above*/
  printf("Current status of open file descriptor: %d\n",flags);
  close(n);
  return 0;
}
