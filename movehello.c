#include <ncurses.h>
#include "movehello.h"

static const char message[] = "Hello, world!";
enum {key_escape=27};

#if 0
static void show_message(int x, int y)
{
  move(x,y);
  addstr(message);
  refresh();
}
#endif

#if 1
static void show_message(int x, int y)
{
  move(x,y);
  addstr(message);
  move(0,0);
  printw("(%d,%d)     ", x, y);
  refresh();
}
#endif

static void hide_message(int x, int y)
{
  int i;
  move(x,y);
  for (i=0; i< sizeof(message)-1; i++)
    addch(' ');
  refresh();
}

static void check (int *coord, int max)
{
  if(*coord < 0)
    *coord=0;
  else
    if(*coord > max)
      *coord=max;
}

static void move_message(int *x, int *y, int mx, int my, int dx, int dy)
{
  hide_message(*x,*y); /*give there value within x and y*/
  *x+=dx; 
  check(x,mx); /*give pointer as a parameter*/
  *y+=dy;
  check(y,my);
  show_message(*x,*y); /*give int within pointers*/
}

static void handle_resize(int *x, int *y, int *mx, int *my)
{
  int row, col;
  getmaxyx(stdscr, row, col);
  *mx=col-sizeof(message)+1;  /*?*/
  *my=row-1;
  hide_message(*x,*y);
  check(x,*mx);
  check(y,*my);
  show_message(*x,*y);
}

int main()
{
  int row, col, x, y, max_x, max_y, key;
  initscr();
  cbreak(); /*provide using ctrl+c e.d*. raw() is alternative*/
  keypad(stdscr, 1); /*turn on escape sequences via "1"*/
  noecho(); /*disable any typing that can output on terminal*/
  curs_set(0);
  getmaxyx(stdscr,row, col);
  y=row/2;
  x=(col - (sizeof(message)-1))/2;
  max_x = col - sizeof(message) + 1;
  max_y = row-1;
  show_message(x,y);
  while((key=getch()) != key_escape)
    {
      switch(key)
	{
	case KEY_UP:
	  move_message(&x,&y,max_x,max_y,0,-1);
	  break;
	case KEY_DOWN:
	  move_message(&x,&y,max_x,max_y,0,1);
	  break;
	case KEY_LEFT:
	  move_message(&x,&y,max_x,max_y,-1,0);
	  break;
	case KEY_RIGHT:
	  move_message(&x,&y,max_x,max_y,1,0);
	  break;
	case KEY_RESIZE:
	  handle_resize(&x,&y,&max_x,&max_y);
	  break;
	}
    }
  endwin();
  return 0;
}
