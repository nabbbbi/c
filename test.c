#include <stdio.h>
#include <stdlib.h>

void string_copy(char *dest, const char *src)
{
  while(*src)
    {
      *dest++=*src++;
    }
  *dest=0;
}


