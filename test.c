#include <stdlib.h>
#include <stdio.h>
#include "pointer_rsln.h"

void int_callback_print(int n, void *userdata) /* user-a get from
						  ext function */
{
  printf("%d",n); 
}

void int_bin_tree_traverse(struct node *root,
			   void (*int_callback_print)(int, void*),
			   void *userdata)
{
  if(!root)
    return;
  int_bin_tree_traverse(root->left,int_callback_print,userdata);
  (*int_callback_print)(root->data,userdata);
  int_bin_tree_traverse(root->right,int_callback_print,userdata);
}

int main()
{
  int i;
  void *userdata;
  int m[] = {35,-44,15,-5,67,37,334,22,-14,98,42,11};
  struct node *f = NULL;
  for(i=0; i < sizeof(m)/sizeof(*m); i++)
    {
      add_int_to_bintree(&f,m[i]);
    }
  int_bin_tree_traverse(f,int_callback_print,userdata);
  return 0;
}
