#include <stdio.h>
#include <stdlib.h>

struct item {
  int data;
  struct item *next;
};

struct item *int_array_to_list(const int *arr, int len)
{
  struct item *tmp;
  if (!len)
    return NULL;
  tmp = malloc(sizeof(struct item));
  tmp->data = *arr;
  tmp->next = int_array_to_list(arr + 1, len - 1);
  return tmp;
}

int main()
{
  struct item *f; 
  int m[] = {3,5,5,2,5,1};
  f = int_array_to_list(m,sizeof(m));
  printf("the first intex is: %d\n size of array: %ld\n size of struct: %ld\n",f->data, sizeof(m), sizeof(*f));
  return 0;
}
