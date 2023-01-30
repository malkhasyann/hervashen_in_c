#ifndef SUN
#define SUN

struct sun_t;

struct sun_t* sun_malloc();

void sun_init(struct sun_t*);
void sun_destroy(struct sun_t*);

int sun_get_is_shining(struct sun_t*);
void sun_set_is_shining(struct sun_t*, int);

void sun_display(struct sun_t*);

#endif