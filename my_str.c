#include <stdio.h>
#include "str.h"

#if 0 
void copy_string(char *dest, const char *src)
{
  int i;
  for (i=0; src[i]; i++)
    dest[i]=src[i];
  dest[i]=0;
}
#endif
#if 0
void copy_string(char *dest, const char *src)
{
  while(*src)
    {
      *dest=*src;
      dest++;
      src++;
    }
  *dest=0;
}
#endif
#if 0
void copy_string(char *dest, const char *src)
{
  for (;*src; src++, dest++)
    {
      *dest=*src;
    }
  *dest=0;
}
#endif
#if 1
void copy_string(char *dest, const char *src)
{
  while((*dest++=*src++))
    {
    }
}
#endif

#if 1
int string_length(const char *str) /*calculate the lenth of string*/
{
  const char *p;
  p=str;
  while(*p)
    p++;
  return p - str;
}
#endif

#if 0
int string_length(const char *str)
{
  int i;
  i=0;
  while (str[i] != '\0')
    i++;
  return i;
}
#endif

#if 0
int string_length(const char *str)
{
  int i;
  for (i=0; str[i]; i++)
    {}
  return i;
}
#endif
#if 0
int string_length(const char *str)
{
  const char *p;
  for(p=str; *p; p++)
    {}
  return p - str;
}
#endif
#if 0
int string_length(const char *str)
{
  const char *p;
  while(*p++)
    {}
  return str - p;
}
#endif
int main ()
{
  int n;
  static char m[40];
  n=string_length("Hello World!");
  copy_string(m,"Hello World!");
  printf("%s\n%d\n", m, n);
  return 0;
}
