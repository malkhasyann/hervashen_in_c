#include <stdlib.h>
#include <stdio.h>

// oxygen: type definition
typedef struct 
{
    int volume;
} oxygen_t;

// oxygen: memory allocation
oxygen_t* oxygen_malloc()
{
    return (oxygen_t*)malloc(sizeof(oxygen_t));
}

// oxygen: constructor
void oxygen_init(oxygen_t* this)
{
    this->volume = 500;
}

// oxygen: destructor
void oxygen_destroy(oxygen_t* this) {}

// oxygen: getter(volume)
int oxygen_get_volume(oxygen_t* this)
{
    return this->volume;
}

// oxygen: setter(volume)
void oxygen_set_volume(oxygen_t* this, int volume)
{
    if (volume <= 0)
        this->volume = 0;
    else
        this->volume = volume;
}

// oxygen: display info
void oxygen_display(oxygen_t* this)
{
    printf("Oxygen volume in air: %d\n", this->volume);
}