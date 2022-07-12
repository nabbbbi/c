#ifndef NEWMODE_H_SENTRY
#define NEWMODE_H_SENTRY

struct node
{
  int data;
  struct node *left, *right;
};

void add_int_to_bintree(struct node **root, int n);
void read_int_in_bintree(struct node *r);

#endif
