#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "dynarray/dynarray.h"

#include "oxygen.h"
#include "grass.h"
#include "sun.h"
#include "tree.h"
#include "frog.h"


// world: type definition
typedef struct 
{
    struct sun_t* sun;
    struct oxygen_t* oxygen;
    struct grass_t* grass;
    struct frog_t** animals;
    struct tree_t** trees;
    int clock;
} world_t;

// world: memory allocation
world_t* world_malloc()
{
    return (world_t*)malloc(sizeof(world_t));
}

// world: constructor
void world_init(
    world_t* this,
    struct sun_t* sun,
    struct oxygen_t* oxygen,
    struct grass_t* grass,
    struct frog_t** animals,
    struct tree_t** trees,
    int clock)
{
    srand(time(NULL));
    this->sun = sun;
    this->oxygen = oxygen;
    this->grass = grass;
    this->animals = animals;
    this->trees = trees;
    this->clock = clock;
}

// world: destroy
void world_destroy(world_t* this)
{
    sun_destroy(this->sun);
    oxygen_destroy(this->oxygen);
    grass_destroy(this->grass);
    dynarray_destroy(this->animals);
    dynarray_destroy(this->trees);
    free(this->sun);
    free(this->oxygen);
    free(this->grass);
    free(this->animals);
    free(this->trees);
}

// private: whether it is day or night
int __is_day(world_t* this)
{
    return (this->clock >= 7 && this->clock <= 18);
}

// private: all trees work
void __trees_work(world_t* this)
{
    for (int i = 0; i < dynarray_length(this->trees); i++)
    {
        oxygen_set_volume(
            this->oxygen,
            oxygen_get_volume(this->oxygen) + 
            tree_photosynthesis(this->trees[i]));
    }
}


// private: all animals move
void __animals_move(world_t* this)
{
    for (int i = 0; i < dynarray_length(this->animals); i++)
    {
        frog_move(this->animals[i]);
    }
}

// private: all animals eat
void __animals_eat(world_t* this)
{
    for (int i = 0; i < dynarray_length(this->animals); i++)
    {
        if(rand() % 2)
            frog_eat(this->animals[i], this->grass);
    }
}

// private: all animals breath
void __animals_breath(world_t* this)
{
    for (int i = 0; i < dynarray_length(this->animals); i++)
    {
        frog_breath(this->animals[i], this->oxygen);
    }
}

// private: all animals go to sleep
void __animals_sleep(world_t* this)
{
    for (int i = 0; i < dynarray_length(this->animals); i++)
    {
        if (frog_get_is_awake(this->animals[i]))
            frog_sleep(this->animals[i]);
    }
}

// private: all animals wake up
void __animals_wake_up(world_t* this)
{
    for (int i = 0; i < dynarray_length(this->animals); i++)
    {
        if (!frog_get_is_awake(this->animals[i]))
            frog_wake_up(this->animals[i]);
    }
}

// private: all animals get hungry
void __animals_get_hungry(world_t* this)
{
    for (int i = 0; i < dynarray_length(this->animals); i++)
    {
        frog_get_hungry(this->animals[i]);
    }
}

// private: display all animals
void __animals_get_info(world_t* this)
{
    printf("--------------------------\n");
    printf("Animals:\n");
    for (int i = 0; i < dynarray_length(this->animals); i++)
    {
        printf("  ");
        frog_display(this->animals[i]);
    }
    printf("--------------------------\n");
}

// private: display all trees
void __trees_get_info(world_t* this)
{
    printf("--------------------------\n");
    printf("Trees:\n");
    for (int i = 0; i < dynarray_length(this->trees); i++)
    {
        printf("\t");
        tree_display(this->trees[i]);
    }
    printf("--------------------------\n\n");
}

// private: collect dead animals
void __collect_dead_animals(world_t* this)
{
    struct frog_t** alive = dynarray_create(struct frog_t*);
    for (int i = 0; i < dynarray_length(this->animals); i++)
    {
        if (frog_is_dead(this->animals[i]))
        {
            frog_dead_message(this->animals[i]);
            continue;
        }
        dynarray_push(alive, this->animals[i]);
    }
    dynarray_destroy(this->animals);
    this->animals = alive;
}

// world: display info
void world_display(world_t* this)
{
    printf("It is %d o'clock\n", this->clock);
    sun_display(this->sun);
    oxygen_display(this->oxygen);
    __animals_get_info(this);
    __trees_get_info(this);
}

// world: add an animal
void world_add_animal(world_t* this, struct frog_t* frog)
{
    dynarray_push(this->animals, frog);
}

// world: add a tree
void world_add_tree(world_t* this, struct tree_t* tree)
{
    dynarray_push(this->trees, tree);
}

//world: run the loop
void world_run(world_t* this)
{
    while (1)
    {
        system("clear");
        world_display(this);
        if (__is_day(this))
        {
            sun_set_is_shining(this->sun, 1);
            __trees_work(this);
            __animals_wake_up(this);
            __animals_move(this);
            __animals_eat(this);
            __animals_breath(this);
        }
        else
        {
            sun_set_is_shining(this->sun, 0);
            __animals_sleep(this);
        }
        __animals_get_hungry(this);
        __collect_dead_animals(this);
        usleep(1500000);
        this->clock = (this->clock + 1) % 24;
    }
}