#include <time.h>
#include <stdio.h>

struct tm;
char *p;

int main()
{
  time_t n;
  struct tm *t;
  n=time(&n);
  t=gmtime(&n);
  p=asctime(t);
  printf(" year %d  month %d  day %d hour %d minute %d seconds%d \n",t->tm_year,t->tm_mon,t->tm_wday, t->tm_hour,t->tm_min, t->tm_sec);
  printf("%s\n",p);
  return 0;
}
