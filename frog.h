#ifndef FROG
#define FROG

#include "oxygen.h"
#include "grass.h"

struct frog_t;

struct frog_t* frog_malloc();

void frog_init(
    struct frog_t*,
    const char*,
    int*, int, int,
    int, int);

void frog_destroy(struct frog_t*);

char* frog_get_name(struct frog_t*);

int* frog_get_pos(struct frog_t*);
void frog_move(struct frog_t*);

int frog_get_is_awake(struct frog_t*);
void frog_set_is_awake(struct frog_t*, int);

int frog_get_lung(struct frog_t*);
int frog_get_is_breathing(struct frog_t*);
void frog_breath(struct frog_t*, struct oxygen_t*);

void frog_wake_up(struct frog_t*);
void frog_sleep(struct frog_t*);

void frog_eat(struct frog_t*, struct grass_t*);
void frog_get_hungry(struct frog_t*);

int frog_is_dead(struct frog_t*);
void frog_dead_message(struct frog_t*);

void frog_display(struct frog_t*);

#endif