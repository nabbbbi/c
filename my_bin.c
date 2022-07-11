#include <stdio.h>
#include <stdlib.h>
#include "string_rsln.h"

/* #include "/home/pi/git/c/test.h" */

struct node
{
  int data;
  char message[250];
  struct node *left, *right;
};

void add_to_bintree(struct node **root, int n, char *m) /* will change pointer */
{
  if(!*root)
    {
      *root=malloc(sizeof(**root)); /*for next *root in the next 
				      element */
      copy_string_rsln((*root)->message,m);
      (*root)->data = n;
      (*root)->left = NULL;
      (*root)->right = NULL;
      return;
    }
  if (n == (*root)->data)
    return;
  if (n < (*root)->data)
    add_to_bintree(&(*root)->left, n,m);
  else
    add_to_bintree(&(*root)->right, n,m);
}

void read_bintree(struct node *r)
{
  if (!r) /* if root = NULL */
    return;
  read_bintree(r->left);
  printf("%d %s\n",r->data, r->message);
  read_bintree(r->right);
}

int main()
{
  struct node *root=NULL;
  int n;
  char *m = "HELLO";
  n=3;
  add_to_bintree(&root,n,m);
  read_bintree(root);
  return 0;  
}
