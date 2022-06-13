/*curses_hello.c*/
#include <unistd.h>
#include <curses.h>

const char message[] = "Hello, World!";
enum {delay_duration=30};

int main()
{
  int row, col;
  initscr(); /*begin ncurses*/
  getmaxyx(stdscr,row,col); /*put unto vars horisontal and vertical values increases by 
			      max because of stdscr*/
  move(row/2,(col-(sizeof(message)-1))/2); /*move cursor to certain place in screen*/
  addch(55 | A_BOLD | A_BLINK); /*add to this moved place string*/
  curs_set(0); /*cursor will disappear*/
  refresh(); /*refresh to activate changes*/
  sleep(delay_duration); /*wait*/ 
  endwin(); /*end of ncurses*/
  return 0;
}
