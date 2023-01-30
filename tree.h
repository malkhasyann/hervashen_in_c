#ifndef TREE
#define TREE

struct tree_t;

struct tree_t* tree_malloc();

void tree_init(struct tree_t*, int*);
void tree_destroy(struct tree_t*);

int* tree_get_pos(struct tree_t*);
int tree_photosynthesis(struct tree_t*);

void tree_display(struct tree_t*);

#endif