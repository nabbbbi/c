#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
  #if 0
  int p;
  p = fork();
  if (p == 0)
    printf("I'm the child\n");
  else
  printf("I'm the parent\n");
  #endif
  #if 1
  int p;
  p = fork();
  if (p == 0)
    {
      printf("I'm the child\n");
      exit(0);
    }
  printf("I'm the parent\n");
  #endif
  return 0;
}
