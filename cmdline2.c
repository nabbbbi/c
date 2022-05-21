#include <stdio.h>

int main(int argc, char **argv) /*array of pointers to cmdarguments*/
{
  while (*argv)
    {
    printf("[%s]\n", *argv); /*s is string that refers to memory*/
    argv++;
  }
  return 0;
}
