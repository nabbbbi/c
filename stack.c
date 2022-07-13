#include <stdlib.h>
#include <stdio.h>
#include "pointer_rsln.h"

int main()
{
  static int m[] = {3,1,5,6,7,2,5,1,6};
  struct item *f;
  f = add_to_list(m,sizeof(m)/4);
  do
    {
      printf("%d\n",f->data);
      f=f->next;
    } while (f);
  return 0;
}

