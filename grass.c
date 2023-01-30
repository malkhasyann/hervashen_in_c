#include <stdlib.h>

// grass: type definition
typedef struct
{
    int point;
} grass_t;

// grass: memory allocation
grass_t* grass_malloc()
{
    return (grass_t*)malloc(sizeof(grass_t));
}

// grass: constructor
void grass_init(grass_t* this, int point)
{
    this->point = 0;
}

// grass: destructor
void grass_destroy(grass_t* this) {}

// grass: getter(point)
int grass_get_point(grass_t* this)
{
    return this->point;
}

// grass: setter(point)
void grass_set_point(grass_t* this, int point)
{
    this->point = point;
}