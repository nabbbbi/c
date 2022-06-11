/*curses_hello.c*/
#include <unistd.h>
#include <curses.h>

const char message[] = "Hello, World!";
enum {delay_duration=30};

int main()
{
  int row, col;
  initscr();
  getmaxyx(stdscr,row,col);
  move(row/2,(col-(sizeof(message)-1))/2);
  addstr(message);
  curs_set(0);
  refresh();
  sleep(delay_duration); /*after 5 seconds end*/
  endwin();
  return 0;
}
