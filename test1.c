#include <stdio.h>
#include <ncurses.h>

int main()
{
  initscr();
  attron(A_BOLD);
  addstr("Hello");
  refresh();
  endwin();
  return 0;
}
