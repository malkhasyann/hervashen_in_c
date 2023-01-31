#include <stdio.h>
#include <stdlib.h>

#include "dynarray/dynarray.h"

#include "grass.h"
#include "oxygen.h"
#include "sun.h"
#include "tree.h"
#include "frog.h"
#include "world.h"


int main()
{
    // allocation
    struct grass_t* grass = grass_malloc();
    struct oxygen_t* oxygen = oxygen_malloc();
    struct sun_t* sun = sun_malloc();
    struct tree_t* tree = tree_malloc();
    struct frog_t* frog1 = frog_malloc();
    struct frog_t* frog2 = frog_malloc();
    struct world_t* world = world_malloc();

    // construct: grass, oxygen, sun, tree and frogs
    grass_init(grass);
    oxygen_init(oxygen);
    sun_init(sun);

    int* pos = malloc(2 * sizeof(int));
    pos[0] = 2;
    pos[1] = 3;
    tree_init(tree, pos);

    pos[0] = 5;
    pos[1] = 5;
    frog_init(frog1, "Chunchurik", pos, 1, 1, 25, 5);

    pos[0] = 7;
    pos[1] = 8;
    frog_init(frog2, "Hayr Chunchur", pos, 1, 1, 10, 4);

    // creating dynamic arrays
    struct frog_t** animals = dynarray_create(struct frog_t*);
    dynarray_push(animals, frog1);
    dynarray_push(animals, frog2);
    struct tree_t** trees = dynarray_create(struct tree_t*);
    dynarray_push(trees, tree);

    // construct world
    world_init(
        world,
        sun,
        oxygen,
        grass,
        animals,
        trees,
        8
    );

    // create a tree
    struct tree_t* tree2 = tree_malloc();
    pos[0] = -11;
    pos[1] = -11;
    tree_init(tree2, pos);
    world_add_tree(world, tree2);

    // add an animal in world 
    struct frog_t* frog3 = frog_malloc();
    pos[0] = 18;
    pos[1] = 18;
    frog_init(frog3, "Chunchurik Junior", pos, 1, 1, 30, 3);
    world_add_animal(world, frog3);

    world_run(world);

    return 0;
}