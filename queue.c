#include <stdlib.h>
#include <stdio.h>

static int m[] = {3,1,5,6,7,2,5,1,6};

struct item
{
  int data;
  struct item *next, *last;
};

struct item *add_to_list(int *arr, int len)
{
  struct item *first=NULL, *last=NULL, *tmp;
  int i;
  for(i=0; i<len; i++)
    {
      tmp=malloc(sizeof(struct item));
      tmp->data = arr[i];
      tmp->next = NULL;
      if(last)
	{
	  last->next=tmp;
	  last=last->next;
	}
      else
	{
	  first=last=tmp; /*only way to save first pointer.
			    last just assign first element*/
	}
    }
  return first;
}

int main()
{
  struct item *f;
  f=add_to_list(m,sizeof(m)/4);
  do
    {
      printf("%d\n",f->data);
      f=f->next;
    } while (f);
  return 0;
}
