#include "callback.h"
#include <stdio.h>
#include <stdlib.h>

struct node
{
  int val;
  struct node *left, *right; 
};

#if 0
void int_callback_sum(int data, void *userdata)
{
  *(int*)userdata += data;
}
#endif

#if 1
void int_callback_sum(int data, void *userdata)
{
  int *sum = userdata;
  *sum+=data;
}
#endif

void int_bin_tree_print_loop(struct node *r,
			     void (*callback)(int, void*),
			     void* userdata)
{
  if(!r)
    return;
  int_bin_tree_print_loop(r->left, callback, userdata);
  (*callback)(r->val, userdata);
  int_bin_tree_print_loop(r->right, callback, userdata);
}

void add_to_tree(struct node **root, int n)
{
  if (!*root)
    {
      *root=malloc(sizeof(**root));
      (*root)->left=NULL;
      (*root)->right=NULL;
      (*root)->val=n;
    }
  if ((*root)->val == n)
    return;
  if ((*root)->val < n)
    add_to_tree(&(*root)->left, n);
  else
    add_to_tree(&(*root)->right, n);
}

int main ()
{
  struct node *p= NULL;
  static const int vals[] =
    {
      50, 25, 75, 15, 30, 60, 90, 10, 20, 40,
      60, 70, 80, 95, 5, 35, 45, 55, 65, 85 
    };
  int sum,i;
  sum= 0;
  for (i=0; i< sizeof(vals) / sizeof(int); i++)
    add_to_tree(&p,vals[i]);
  int_bin_tree_print_loop(p,int_callback_sum, &sum);
  printf("%d", sum);
  return 0;
}
