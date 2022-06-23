#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
static const char error[] = "Can't open";

int main()
{
  int save1,fd;
  fflush(stdout); /*clean standart output*/
  save1 = dup(1); /*save our standart output*/
  fd = open("/home/pi/test/out.txt",O_CREAT | O_WRONLY | O_TRUNC, 0666);
  /*opened file*/
  if (fd == -1)
    {
      write(2,error,sizeof(error));
      return 1;
    }
  dup2(fd,1); /*transform opened file to standart output*/
  close(fd); /*closed unnesecessary descriptor (not file)*/
  printf("hello");
  dup2(save1,1); /*rehab standart output. file close automatically*/
  close(save1); /*delete copy*/
  return 0;
}
