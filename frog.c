#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "oxygen.h"
#include "grass.h"

// frog: type definition
typedef struct 
{
    char* name;
    int is_awake;
    int is_breathing;
    int stomach;
    int* pos;
    int lung;
} frog_t;

// frog: memory allocation
frog_t* frog_malloc()
{
    return (frog_t*)malloc(sizeof(frog_t));
}

// frog: constructor
void frog_init(
    frog_t* this,
    const char* name,
    int* pos,
    int is_awake,
    int is_breathing,
    int stomach,
    int lung)
{
    srand(time(NULL));
    this->name = (char*)malloc(20 & sizeof(char));
    strcpy(this->name, name);
    this->is_awake = is_awake;
    this->is_breathing = is_breathing;
    this->stomach = stomach;
    this->pos = (int*)malloc(2 * sizeof(int));
    this->pos[0] = pos[0];
    this->pos[1] = pos[1];
    this->lung = lung;
}

// frog: destructor
void frog_destroy(frog_t* this)
{
    free(this->name);
    free(this->pos);
}

// frog: getter(name)
char* frog_get_name(frog_t* this)
{
    return this->name;
}

// frog: getter(pos)
int* frog_get_pos(frog_t* this)
{
    return this->pos;
}

// frog: random move
void frog_move(frog_t* this)
{
    int random_x = rand() % 3 - 1;
    int random_y = rand() % 3 - 1;
    this->pos[0] += random_x;
    this->pos[1] += random_y;
}

// frog: getter(is awake)
int frog_get_is_awake(frog_t* this)
{
    return this->is_awake;
}

// frog: setter(is awake)
void frog_set_is_awake(frog_t* this, int value)
{
    if (value == 0)
        this->is_awake = 0;
    else
        this->is_awake = 1;
}

// frog: getter(lung)
int frog_get_lung(frog_t* this)
{
    return this->lung;
}

// frog: getter(is breathing)
int frog_get_is_breathing(frog_t* this)
{
    return this->is_breathing;
}

// frog: breath the oxygen
void frog_breath(frog_t* this,struct oxygen_t* oxygen)
{
    if (oxygen_get_volume(oxygen) < frog_get_lung(this))
    {
        this->stomach = 0;
        return;
    }
    oxygen_set_volume(oxygen,
        oxygen_get_volume(oxygen) - frog_get_lung(this));
}

// frog: wake up
void frog_wake_up(frog_t* this)
{
    this->is_awake = 1;
    this->is_breathing = 1;
}

// frog: sleep
void frog_sleep(frog_t* this)
{
    this->is_awake = 0;
    this->is_breathing = 0;
}

// frog: eat grass
void frog_eat(frog_t* this, struct grass_t* grass)
{
    printf("%s is eating grass.\n", this->name);
    this->stomach += grass_get_point(grass);
    if (this->stomach > 12)
        this->stomach = 50;
}

// frog: geting hungry
void frog_get_hungry(frog_t* this)
{
    this->stomach -= 1;
}

// frog: starve to death
int frog_is_dead(frog_t* this)
{
    return this->stomach <= 0;
}

// frog: dead message
void frog_dead_message(frog_t* this)
{
    printf("%s is dead", this->name);
}

// frog: display info
void frog_display(frog_t* this)
{
    printf("%s at {%d, %d}:\n\t",
        this->name,
        this->pos[0],
        this->pos[1]);
    if (this->is_awake)
        printf("awake ");
    else
        printf("sleeping ");
    printf("and is ");
    if (this->is_breathing == 0)
        printf("not ");
    printf("breathing.\n\t");
    printf("Stomach %d points.\n", this->stomach);
}