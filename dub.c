#include <stdio.h>
#include <unistd.h>
static const error[] = "Can't open";

int main()
{
  int save1,fd;
  fflush(stdout);
  save1 = dup(1);
  int fd = open("/home/pi/test/out.txt",O_CREAT | O_WRONLY | O_TRUNC, 0666);
  if (fd == -1)
    {
      write(2,error,sizeof(error));
      return 1;
    }
  dup2(fd,1);
  printf("hello");
  close(fd);
  dup2(save1,1);
  close(save1);
  return 0;
}
