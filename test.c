#include <stdio.h>
#include <stdlib.h>

struct mes
{
  char buf[250];
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
  char buf2[50];
  scanf("%s",buf2);
  struct mes st;
  char *message = "hello";
  string_copy(st.buf,message);
  printf("%s %s\n",st.buf,buf2);
  return 0;
}

