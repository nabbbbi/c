#include "string_rsln.h"
#include <stdio.h>
#include <string.h>

int main()
{
  int n;
  char s[50];
  char *buf = "Hello";
  n = string_len_rsln(buf);
  memset(&s,'-',n);
  printf("%s\n%s\n",buf,s);
  return 0;
}
