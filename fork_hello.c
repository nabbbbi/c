#include <stdio.h>
#include <unistd.h>

int main()
{
  #if 0
  printf("hello world!\n");
  fork();
  return 0;
  #endif

  #if 0
  printf("hello, world");
  _exit(0);
  #endif

  #if 1
  printf("hello, world\n");
  _exit(0);
  #endif
}
