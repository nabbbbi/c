/* print_n */
#include <stdio.h>

void print_n(char c, int n) { /* just print n symbols*/
  int k;
  for (k = 0; k < n; k++)
    printf("%c", c);
}

int main () {
  int n;
  char c;
  n = 10;
  scanf("%c",&c);
  print_n(c,n);
  return 0;
}
