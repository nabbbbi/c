#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
  int i;
  void *z;
  char *c = "f";
  z=c;
  write(1,z,1);
  write(1,"\n",1);
  return 0;
}
