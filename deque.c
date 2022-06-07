#include <stdio.h>
#include <stdlib.h>

struct item {
  double data;
  struct item *next, *prev;
};

struct item *add_first_deque(double x)
{
  struct item *first=NULL, *last=NULL, *tmp;
  tmp=malloc(sizeof(struct item));
  tmp->data=x;
  tmp->prev=NULL;
  tmp->next=first;
  if (first)
    {
      first->prev=tmp; /*here we bound already existing first element with*/
    } /*future first aka tmp.*/
  else
    {
      last=tmp; /*last will be NULL because first=NULL*/
    }
  first=tmp; /*new first element added*/
  return first;
}

struct item *add_last_deque(double x)
{
  struct item *first=NULL, *last=NULL, *tmp;
  tmp=malloc(sizeof(struct item));
  tmp->data=x;
  tmp->next=NULL;
  tmp->prev=last;
  if (last)
    {
      last->next=tmp;
    }
  else
    {
    first=tmp;
    }
  last=tmp;
  return last;
}

void del_first_element(struct item *first)
{
  if (first)
    {
      struct item *last, *tmp=first;
      first=first->next;
      if(first)
	first->prev=NULL;
      else
	last=NULL;
      free(tmp);
    }
}

void del_first_element(struct item *last)
{
  if (last)
    {
      struct item *first, *tmp=last;
      last=last->next;
      if(last)
	last->next=NULL;
      else
	first=NULL;
      free(tmp);
    }
}

int main()
{
  struct item *first, *last;
  double x;
  x=3.1;
  last=add_last_deque(x);
  first=add_first_deque(x);
  printf("%f %f",first->data,last->data);
  return 0;
}
