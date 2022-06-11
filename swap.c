#include <stdio.h>

void swap(int *a, int *b)
{
  int t;
  t=*a;
  *a=*b;
  *b=t;
}

int main()
{
  int x,y;
  x=4;
  y=20;
  swap(&x,&y);
  printf("%d %d\n", x, y);
  return 0;
}
