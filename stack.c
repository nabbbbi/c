#include <stdlib.h>
#include <stdio.h>

static int m[] = {3,1,5,6,7,2,5,1,6};

struct item {
  int data;
  struct item *next;
};

struct item *add_to_list(int *arr, int len)
{
  struct item *first=NULL, *tmp;
  int i;
  for (i=0; i < len; i++)
    {
      tmp = malloc(sizeof(struct item));
      tmp->data= arr[i];
      tmp->next = first;
      first=tmp;
    }
  return first;
}

int main()
{
  struct item *f;
  f = add_to_list(m,sizeof(m)/4);
  do
    {
      printf("%d\n",f->data);
      f=f->next;
    } while (f);
  return 0;
}

