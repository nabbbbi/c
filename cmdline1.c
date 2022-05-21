#include <stdio.h>

int main(int argc, char **argv) /*array of pointers to cmdarguments*/
{
  int i;
  for (i=1; i < argc; i++)
    printf("[%s]\n", argv[i]); 
  return 0;
}
