#ifndef OXYGEN
#define OXYGEN

struct oxygen_t;

struct oxygen_t* oxygen_malloc();

void oxygen_init(struct oxygen_t*);
void oxygen_destroy(struct oxygen_t*);

int oxygen_get_volume(struct oxygen_t*);
void oxygen_set_volume(struct oxygen_t*, int);

void oxygen_display(struct oxygen_t*);

#endif