#ifndef NEWMODE_H_SENTRY
#define NEWMODE_H_SENTRY

struct node
{
  int data;
  struct node *left, *right;
};

struct item
{
  int data;
  struct item *next;
};


void add_int_to_bintree(struct node **root, int n);
void read_int_in_bintree(struct node *r);
struct item *list_to_stack(int *arr, int len);
struct item *list_to_queue(int *arr, int n);

int div7(int n);
void delete_from_list_div7(struct item **f, int (*is_div7)(int));

int is_negate(int n);
void delete_from_list_negate(struct item **f, int (*is_negate)(int));

int is_even(int n);
void delete_from_list_even(struct item **f, int (*even)(int));

void int_callback_print(int n, void *userdata);
void int_bin_tree_traverse(struct node *root,
			   void (*int_callback_print)(int, void*),
			   void *userdata);

#endif
