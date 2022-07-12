#include <stdlib.h>
#include <stdio.h>

struct node
{
  int data;
  struct node *left, *right;
};


void read_int_in_bintree(struct node *r)
{
  if(!r)
    {
      read_int_in_bintree(r->left);
      printf("%d",r->data);
      read_int_in_bintree(r->right);
    }
}

void add_int_to_bintree(struct node **root, int n)
{
  if (!*root) 
    {
      *root = malloc(sizeof(**root));
      (*root)->data = n;
      (*root)->left = NULL;
      (*root)->right = NULL;
      return;
    }
  if((*root)->data == n)
    return;
  if((*root)->data > n)
    add_int_to_bintree(&(*root)->left, n);
  else
    add_int_to_bintree(&(*root)->right, n);
}
