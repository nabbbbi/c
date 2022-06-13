#include <stdio.h>
#include <ncurses.h>

enum { key_escape = 27 };
enum { color_count = 8 };
static const int all_colors[color_count] =
  {
    COLOR_BLACK,     /* 0 */
    COLOR_RED,       /* 1 */
    COLOR_GREEN,     /* 2 */
    COLOR_YELLOW,    /* 3 */
    COLOR_BLUE,      /* 4 */
    COLOR_MAGENTA,   /* 5 */
    COLOR_CYAN,      /* 6 */
    COLOR_WHITE      /* 7 */
  };

static int setpair(int fg, int bg)
{
  int n = bg*8 + fg + 1; /* "1" was added to exclude color #0 (interdict) in 
			  * case bg and fg are zero*/
  init_pair(n,fg,bg); /*set color on number n*/
  return n;
}

static void make_line(int line, int width, int fgcolor)
{
  int i, j, w, pn, att;
  w = width/color_count; /*width of screen*/
  for (i=0; i < color_count; i++)
    {
      move(line,i*w);
      pn = setpair(fgcolor, all_colors[i]); /*pn will store number of color pair*/
      for (j=0; j < w; j++) /*fill void bitween i*/
	{
	  att= COLOR_PAIR(pn);
	  if(j % 2 == 0)
	    att |= A_BOLD; /*att | A_BOLD result put in att */
	  if((j / 2) % 2 == 1)
	    att |= A_BLINK;
	  attrset(att);
	  addch('*');
	  refresh();
	}
    }
}

static void make_screen(int h, int w)
{
  int i;
  clear();
  for(i=0; i < h; i++)
    make_line(i, w, all_colors[i % color_count]);
}

static void shift_pairs(int shift)
{
  int i;
  for (i=0; i <= color_count*color_count; i++)
    {
      int fg = (i+shift) % color_count;
      int bg = ((i+shift) / color_count) % color_count;
      init_pair(i,fg, bg);
    }
}

int main()
{
  int row, col, ch, shift;
  initscr();
  if(!has_colors())
    {
      endwin();
      fprintf(stderr, "I can't show colors on a BW screen\n");
      return 1;
    }
  cbreak();
  keypad(stdscr, 1);
  noecho();
  curs_set(0);
  start_color();
  getmaxyx(stdscr, row, col);
  make_screen(row, col);
  shift = 2;
  while ((ch = getch()) != key_escape)
    {
      shift_pairs(shift);
      shift++;
      refresh();
    }
  endwin();
  return 0;
}
