#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *left, *right;
};

void copy_string(char *dest, char *src)
{
  while(src)
    {
      
    }
}

void add_to_bintree(struct node **root, int n)
{
  if(!*root)
    {
      *root=malloc(sizeof(**root));
      (*root)->data = n;
      (*root)->left = NULL;
      (*root)->right = NULL;
      return;
    }
  if (n == (*root)->data)
    return;
  if (n < (*root)->data)
    add_to_bintree(&(*root)->left, n);
  else
    add_to_bintree(&(*root)->right, n);
}

void read_bintree(struct node *r)
{
  if (!r) /* if root = NULL */
    return;
  read_bintree(r->left);
  printf("%d\n",r->data);
  read_bintree(r->right);
}

int main()
{
  struct node *root=NULL;
  static const int m[] = {
    50, 25, 75, 15, 30, 60, 9, 10, 20, 40,
    60, 70, 80, 95, 39, 35, 45, 55, 65, 85
  };
  int i;
  for(i=0; i< sizeof(m)/4; i++)
    add_to_bintree(&root,m[i]);
  read_bintree(root);
  return 0;  
}
