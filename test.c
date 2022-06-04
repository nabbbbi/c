#include <stdio.h>
int main ()
{
  char str[32];
  int n;
  n=35;
  sprintf(str,"%d", n);
  printf("%s\n", str);
  return 0;
}
