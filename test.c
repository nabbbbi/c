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
  int n;
  scanf("%d",&n);
  struct mes st;
  char *message = "hello";
  string_copy(st.buf,message);
  printf("%s\n",st.buf);
  return 0;
}

