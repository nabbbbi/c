#include <stdio.h>

int main ()
{
  int c;
  while ((c=getchar()) != EOF)
    {
      if(c== '\n')
	printf("ok!\n");
    }
  return 0;
}

