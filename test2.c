#include <stdio.h>

char *memset_rsln(char *s, int c, int n)
{
  int i;
  for(i=0; i < n; i++)
    {
      s[i]=c;
    }
  return s;
}

int main(int argc, char **argv)
{
  if(argc < 2)
    {
      printf("no no no");
      return 1;
    }
  char *d;
  d =  memset_rsln(argv[1],'x',5);
  printf("%s\n",d);
  return 0;
}
