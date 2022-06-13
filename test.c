#include <stdio.h>
*#include "int_to_bytes.h"*

void integer_bytes(int n)
{
  union split s;
  int i;
  s.integer = n;
  for (i=0;i<sizeof(int); i++)
    printf("byte %d is %x\n",i, s.bytes[i]);
}

int main()
{
  int n=300;
  integer_bytes(n);
  return 0;
}
