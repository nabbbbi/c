#include <stdio.h>
#include <stdlib.h>

struct mes
{
  
};

void string_copy(char *dest, const char *src)
{
  while(*src)
    {
      *dest++=*src++;
    }
  *dest=0;
}

int main()
{
  char buf[250];
  char *message = "hello";
  string_copy(buf,message);
  printf("%s\n",buf);
  return 0;
}

