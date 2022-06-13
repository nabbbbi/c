#include <stdio.h>
#include "int_to_bytes.h"
#include <ncurses.h>

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
  initscr();
  x = A_BOLD;
  y |= A_BOLD;
  swap(&x,&y);
  printf("%d %d\n", x, y);
  int_byte(x);
  endwin();
  return 0;
}
