#include <stdio.h>

extern char **environ;

int main()
{
  int i;
  for(i=0; environ; i++)
    printf("[%s]",environ[i]);
  return 0;
}
