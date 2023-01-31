#ifndef WORLD
#define WORLD

#include "oxygen.h"
#include "grass.h"
#include "sun.h"
#include "tree.h"
#include "world.h"

struct world_t;

struct world_t* world_malloc();

void world_init(
    struct world_t*,
    struct sun_t*,
    struct oxygen_t*,
    struct grass_t*,
    struct frog_t**,
    struct tree_t**,
    int);
void world_destroy(struct world_t*);

void world_add_animal(struct world_t*, struct frog_t*);
void world_add_tree(struct world_t*, struct tree_t*);

void world_run(struct world_t*);

void world_display(struct world_t*);

#endif