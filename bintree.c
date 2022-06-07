/*bintree.c*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
  int val;
  struct node *left, *right;
};

void int_bin_tree_print_loop(struct node *r)
{
  enum state {start, left_visited, completed}; /*start - we first time
						 in node, left visited - 
						 second time in node, 
						 completed - third time in
						 node*/
  struct backpath
  {
    struct node *p; /*current node*/
    enum state st; /*current state in node*/
    struct backpath *next; /*create stack list just count nodes also 
			     depth of tree. 
			     the first element will be the whole tree e.d*/
  };
  struct backpath *bp, *tmp; /*tmp for create stack list*/
  bp=malloc(sizeof(*bp));
  bp->p=r; /*get from argument of function*/
  bp->st=start;
  bp->next=NULL; /*the first node. we will emulate stack as in recursion 
		   call*/
  while(bp)
    {
      switch(bp->st)
	{
	case start:
	  bp->st=left_visited; /*this state will stuck with node and 
				 wont change anymore.*/
	  if(bp->p->left)
	    {
	      tmp=malloc(sizeof(*tmp));
	      tmp->p=bp->p->left;
	      tmp->st=start;/*!!! this state for next node NOT previous 
			      from 34 line of this code*/
	      tmp->next=bp; /*create next element in the stack*/
	      bp=tmp;
	      continue;
	    }
	  /*no break here*/
	case left_visited:
	  printf("%d\n", bp->p->val);
	  bp->st=completed;
	  if(bp->p->right)
	    {
	      tmp=malloc(sizeof(*tmp));
	      tmp->p=bp->p->right;
	      tmp->st=start;
	      tmp->next=bp;
	      bp=tmp;
	      continue;
	    }
	  /*no break here*/
	case completed:
	  tmp=bp;
	  bp=bp->next;
	  free(tmp);
	}
    }
}

/*the same but recursion mode*/
/*
void int_bin_tree_print_rec(struct node *r)
{
  if(!r)
    return;
  int_bin_tree_print_rec(r->left);
  printf("%d", r->val);
  int_bin_tree_print_rec(r->right);
}
*/

void int_bin_tree_add(struct node **root, int n) /*address of pointer*/
{
  if (!*root) /*only if node is empty*/
    {
      *root=malloc(sizeof(**root));
      (*root)->val=n; 
      (*root)->left=NULL; /*branchs will be empty*/
      (*root)->right=NULL;
      return;
    }
  if ((*root)->val == n) /*n is already exists. no need to add*/
    return;
  if(n < (*root)->val)
    int_bin_tree_add(&(*root)->left,n); /*take address of left branch 
					  of node*/
  else
    int_bin_tree_add(&(*root)->right,n); /*take address of right branch
					   of node*/
}
void int_bin_tree_dispose(struct node *r)
{
  if (!r)
    return;
  int_bin_tree_dispose(r->left);
  int_bin_tree_dispose(r->right);
  free(r);
}
int main()
{
  static const int vals[] = {
    50, 25, 75, 15, 30, 60, 90, 10, 20, 40,
    60, 70, 80, 95, 5, 35, 45, 55, 65, 85
  };
  struct node *root=NULL; /*if not initialize this structure there will be Segmentation Fault*/
  int i;
  for (i=0;i < sizeof(vals) / sizeof(*vals); i++)
    int_bin_tree_add(&root,vals[i]); /*add integers to binary tree*/
  int_bin_tree_print_loop(root); /*print all elements in binary tree*/
  int_bin_tree_dispose(root); /*delete all dynamic elements*/
  printf("number of indexes in array: %ld\nsize of each index: %ld bytes\n",sizeof(vals), sizeof(*vals));
  return 0;
}
