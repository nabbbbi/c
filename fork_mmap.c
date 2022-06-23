#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
static const char error [] = "Can't read";

int main()
{
  int pid, pgs;
  int size = 4096;
  int *ptr;
  pgs = getpagesize();
  size = (size-1 / pgs+1) * pgs;
  ptr=mmap(NULL,size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, 0,0);
  if (ptr == MAP_FAILED)
    {
      write(1,error,sizeof(error));
      return 1;
    }
  pid = fork();
  if (pid == 0)
    {
      printf("child %d\n", ptr[77]); /*child process has access to array of
				       1024 numbers.*/
    }
  else
    {
      ptr[77] = 5;
      printf("parent\n"); /*parent process has to*/
    }
  return 0;
}
