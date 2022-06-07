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
in node, left visited - second time in node, completed - third time in
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
  bp->next=NULL; /*the first node. we will emulate stack as in recursion 
call*/
  bp->st=start;
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
	  printf("%d", bp->p->val);
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
