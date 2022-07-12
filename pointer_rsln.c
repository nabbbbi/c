#include <stdlib.h> /* for malloc */
#include <unistd.h> /* for printf */

struct node
{
  int data;
  struct node *left, *right;
};

void read_int_in_bintree(struct node *r)
{
  if(!r)
    return;
  read_int_in_bintree(r->left);
  write(1, r->data, 4);
  /* printf("%d\n",r->data); */
  read_int_in_bintree(r->right);
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
