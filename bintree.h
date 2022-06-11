#ifndef NEWMOD_N_SENTRY
#define NEWMOD_N_SENTRY
void int_bin_tree_print_loop(struct node *r);
void int_bin_tree_add(struct node *r);
void int_callback_sum(int data, void);
void int_bin_tree_print_loop(struct node *r,
			     void (*callback)(int, void*),
			     void* userdata);
#endif
