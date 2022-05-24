/*getchar2.c Ruslan Gadzhiev */
#include <stdio.h>

int main()
{
  int c,n;
  while ((c = getchar()) != EOF) /*while not end of file*/
    {
      if (c == '\n') 
	printf("%20.6d\n", n); /*first of all we should check; is it end of line. if is it then we type number of letter we have typed*/
      n++; /*standart type*/
    }
  return 0;
}
  
