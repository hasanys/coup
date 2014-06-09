#ifndef __COUP_H__
#define __COUP_H__

#include "coup_player.h"

#define COUP_MIN_PLAYERS 2
#define COUP_MAX_PLAYERS 6
#define COUP_START_COINS 2

typedef struct coup coup_t;

struct coup_cb_set {
    void (*game_over)(coup_t *);
    void (*player_move)(coup_t *, struct coup_player *);
};

coup_t *coup_newgame(int nplayers, const struct coup_cb_set *cb);

#endif
