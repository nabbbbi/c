#include <stdio.h>
#include <stdlib.h>

struct item {
  int data;
  struct item *next;
};

struct item *int_array_to_list(int *arr, int len)
{
  struct item *first=NULL, *last=NULL, *tmp;
  int i;
  for (i=0; i < len; i++)
    {
      tmp = malloc(sizeof(struct item));
      tmp->data=arr[i];
      tmp->next=NULL;
      if (last)
	{
	  last->next=tmp; /*adding to the end of the line*/
	  last=last->next;
	}
      else
	{
	  first=last=tmp; /*first will be with first address. last and tmp not*/
	}
    }
  return first;
}

int main()
{
  struct item *f; 
  int m[] = {3,5,5,2,5,1};
  f = int_array_to_list(m,sizeof(m));
  printf("%d\n",f->data);
  return 0;
}
