#include <stdio.h>
#include "int_to_bytes.h"

void int_byte(int n)
{
  union split s;
  int i;
  s.integer = n;
  for (i=0;i<sizeof(int); i++)
    printf("byte%d is %x\n",i, s.bytes[i]);
}
