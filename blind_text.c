#include <stdio.h>
#include <unistd.h> /*for isatty*/
#include <termios.h>
#include <string.h> /*for memcpy*/

enum { bufsize = 128 };

int main()
{
  struct termios ts1, ts2;
  char buf[bufsize];
  if(!isatty(0)) /*check: terminal input or not*/
    {
      fprintf(stderr, "Not a terminal, sorry\n");
      return 1; 
    }
  tcgetattr(0,&ts1); /* fill ts1 var with current options. 0 is fd. we take
		      management of stdin. The change we set with tcsetattr
		     will change stdin*/
  memcpy(&ts2, &ts1, sizeof(ts1)); /*make copy. dest, src, len*/
  ts1.c_lflag &= ~ECHO; /*~ is bitwise negate. cast off ECHO. (do change)*/
  tcsetattr(0,TCSANOW,&ts1); /*set change (turn off "local echo")*/
  printf("Please blind-type the code: ");
  if (!fgets(buf, sizeof(buf),stdin))
    {
      fprintf(stderr,"Unexpected end of file\n");
      return 1;
    }
  printf("\nThe code  you entered is [%s]\n", buf);
  tcsetattr(0,TCSANOW, &ts2); /*reclaim terminla options*/
  return 0;
}
