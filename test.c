#include <stdio.h>
#include <stdlib.h>

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
