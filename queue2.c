#include <stdio.h>
#include <stdlib.h>

struct item {
  int data;
  struct item *next;
};

struct item *int_array_to_list(int *arr, int len)
{
  struct item *first=NULL, *tmp;
  int i;
  for (i=len-1; i>=0; i--)
    {
      tmp = malloc(sizeof(struct item));
      tmp->data=arr[i];
      tmp->next=first;
      first=tmp;
    }
  return first;
}

int main()
{
  struct item *f; 
  int m[] = {3,5,5,2,5,1};
  f = int_array_to_list(m,sizeof(m));
  printf("the first intex is: %d\n size of array: %ld\n size of struct: %ld\n",f->data, sizeof(m), sizeof(*f));
  return 0;
}
