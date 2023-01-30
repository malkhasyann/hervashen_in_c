#include <stdio.h>
#include <stdlib.h>

// tree: type definition
typedef struct
{
    int* pos;
} tree_t;

// tree: memory allocation
tree_t* tree_malloc()
{
    return (tree_t*)malloc(sizeof(tree_t));
}

// tree: constructor
void tree_init(tree_t* this, int* pos)
{
    this->pos = (int*)malloc(2 * sizeof(int));
    this->pos[0] = pos[0];
    this->pos[1] = pos[1];
}

// tree: destructor
void tree_destroy(tree_t* this)
{
    free(this->pos);
}

// tree: getter(pos)
int* tree_get_pos(tree_t* this)
{
    return this->pos;
}

// tree: photosynthesis
int tree_photosynthesis(tree_t* this)
{
    return 80;
}

// tree: display info
void tree_display(tree_t* this)
{
    printf("Tree at {%d, %d}\n",
            this->pos[0], this->pos[1]);
}