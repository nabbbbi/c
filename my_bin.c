#include <stdio.h>
#include <stdlib.h>
#include "pointer_rsln.h"

int main()
{
  int i;
  struct node *root=NULL;
  static const int m[] = {
    50, 25, 75, 15, 30, 60, 9, 10, 20, 40,
    60, 70, 80, 95, 39, 35, 45, 55, 65, 85
  };
  for (i=0; i < sizeof(m)/sizeof(*m); i++)
    {
      add_int_to_bintree(&root,m[i]);
    }
  read_int_in_bintree(root);
  return 0;  
}
