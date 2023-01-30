#ifndef GRASS
#define GRASS

struct grass_t;

struct grass_t* grass_malloc();

void grass_init(struct grass_t*);
void grass_destroy(struct grass_t*);

int grass_get_point(struct grass_t*);
void grass_set_point(struct grass_t*, int);

void grass_display(struct grass_t*);

#endif