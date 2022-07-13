#include <stdlib.h>
#include <stdio.h>
#include "pointer_rsln.h"

int main()
{
  int m[] = {35,32,15,67,37,334,22,98,42,11};
  struct item *f;
  f = list_to_queue(m,sizeof(m)/sizeof(*m));
  do
    {
      printf("%d\n",f->data);
      f=f->next;
    } while(f);
  return 0;
}
