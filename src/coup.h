#ifndef __COUP_H__
#define __COUP_H__

#define COUP_MIN_PLAYERS 2
#define COUP_MAX_PLAYERS 6
#define COUP_START_COINS 2

typedef struct coup coup_t;

coup_t *coup_newgame(int nplayers);

#endif
