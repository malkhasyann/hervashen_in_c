#include <stdio.h>
#include <stdlib.h>

// sun: type definition
typedef struct
{
    int is_shining;
} sun_t;

// sun: memory allocation
sun_t* sun_malloc()
{
    return (sun_t*)malloc(sizeof(sun_t));
}

// sun: constructor
void sun_init(sun_t* this)
{
    this->is_shining = 0;
}

// sun: destructor
void sun_destroy(sun_t* this) {}

// sun: getter(is_shining)
int sun_get_shining(sun_t* this)
{
    return this->is_shining;
}

// sun: setter(is_shining)
void sun_set_shining(sun_t* this, int value)
{
    if (value == 0)
        this->is_shining = 0;
    else
        this->is_shining = 1;
}

// sun: display info
void sun_display(sun_t* this)
{
    printf("Sun::is_shining: %d\n", this->is_shining);
}