#include <stdio.h>
#include <stdlib.h>

struct item
{
  int data;
  struct item *next;
};
/*addding new elements v1*/
/*struct item *int_array_to_list(int *arr, int len)
{
  struct item *first=NULL,*tmp;
  int i;
  for (i=len-1; i>=0; i--)
    {
      tmp=malloc(sizeof(struct item));
      tmp->data=arr[i];
      tmp->next=first;
      first=tmp;
    }
  return first;
}
*/

/*adding new elements v2(with recursion)*/
struct item *int_array_to_list(int *arr, int len)
{
  struct item *tmp;
  if(!len)
    return NULL;
  tmp = malloc(sizeof(struct item));
  tmp->data=*arr;
  tmp->next=int_array_to_list(arr+1,len-1);
  return tmp;
}

/*deleting dyn.variables v1*/
/*void del(struct item *first)
{
  while(first) 
    {
      struct item *tmp = first; 
      first=first->next;
      free(tmp);
    }
}*/

/*deleting variables v2(with recursion)*/
void del(struct item *first)
{
  if(!first)
    return;
  del(first->next);
  free(first);
}

/*delect all negative elements for the list*/
void del_negate(struct item **pcur)
{
  while(*pcur) /*while not element not NULL*/
    {
      if((*pcur)->data < 0)
	{
	  struct item *tmp = *pcur;
	  *pcur=(*pcur)->next;
	  free(tmp);
	}
      else
	{
	  pcur=&(*pcur)->next;
	}
    }
}

/*calculate sum*/
int sum(struct item *first)
{
  int sum=0;
  struct item *tmp=first;
  while (tmp)
    {
      sum+=tmp->data;
      tmp=tmp->next;
    }
  return sum;
}

int main()
{
  int m[] = {-1,2,4,5,6,7,3,4,5};
  struct item *f;
  f=int_array_to_list(m,sizeof(m));
  sum(f);
  del_negate(&f);
  printf("%d\n",f->data);
  del(f);
  return 0;
}
