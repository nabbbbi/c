#include <stdlib.h> /* for malloc */
#include <stdio.h> /* for printf */

/* Binary trees */
struct node
{
  int data;
  struct node *left, *right;
};

/* Linear lists */
struct item
{
  int data;
  struct item *next;
};

/* Binary trees */
void read_int_in_bintree(struct node *r)
{
  if(!r)
    return;
  read_int_in_bintree(r->left);
  printf("%d\n",r->data);
  read_int_in_bintree(r->right);
}

/* Binary trees */
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

/* Linear lists */
struct item *list_to_stack(int *arr, int len)
{
  struct item *first=NULL, *tmp;
  int i;
  for (i=0; i < len; i++)
    {
      tmp = malloc(sizeof(struct item));
      tmp->data= arr[i];
      tmp->next = first;
      first=tmp;
    }
  return first;
}

/* Linear lists */
struct item *list_to_queue(int *arr, int n)
{
  int i;
  struct item *tmp, *first=NULL, *last=NULL;
  for(i=0; i < n; i++)
    {
      tmp = malloc(sizeof(struct item));
      tmp->data = arr[i];
      if(last)
	{
	  last->next=tmp;
	  last=last->next;
	}
      else
	{
	  first=last=tmp;
	} 
    }
  return first;
}

#if 0
/* Linear lists */
void delete_from_list(struct item **f)
{
  while(*f)
    {
      struct item *tmp;
      if((*f)->data < 0)
	{
	  tmp=*f;
	  *f=(*f)->next;
	  free(tmp);
	}
      else
	f=&(*f)->next;
    }
}

#else
/* Linear lists (recursion) */
void delete_from_list(struct item **f)
{
  if(!*f)
    return;
  delete_from_list(&(*f)->next);
  if((*f)->data < 0)
    {
      struct item *tmp = *f;
      *f=(*f)->next;
      free(tmp);
    }
}

#endif

/* Linear lists */
int is_even(int n)
{
  return n % 2 == 0;
}

void delete_from_list_even(struct item **f, int (*even)(int))
{
  while(*f)
    {
      struct item *tmp;
      if((*is_even)((*f)->data))
	{
	  tmp=*f;
	  *f=(*f)->next;
	  free(tmp);
	}
      else
	f=&(*f)->next;
    }
}

/* Linear lists */
int is_negate(int n)
{
  return n < 0;
}

void delete_from_list_negate(struct item **f, int (*is_negate)(int))
{
  while(*f)
    {
      struct item *tmp;
      if((*is_negate)((*f)->data))
	{
	  tmp=*f;
	  *f=(*f)->next;
	  free(tmp);
	}
      else
	f=&(*f)->next;
    }
}

/* Linear lists */
int div7(int n)
{
  return n % 7 == 0;
}

void delete_from_list_div7(struct item **f, int (*is_div7)(int))
{
  while(*f)
    {
      struct item *tmp;
      if((*is_div7)((*f)->data))
	{
	  tmp=*f;
	  *f=(*f)->next;
	  free(tmp);
	}
      else
	f=&(*f)->next;
    }
}
