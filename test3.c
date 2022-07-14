#include <stdlib.h>
#include <stdio.h>
#include "pointer_rsln.h"

void fuction(struct node *f);

int main()
{
  int sum = 0;
  struct node *f = NULL;
  int_bin_tree_traverse(f,int_callback_sum, &sum);
  printf("%d\n", sum);
  return 0;
}
