#ifndef __COUP_PLAYER_H__
#define __COUP_PLAYER_H__

#include "carddeck.h"

struct coup_player {
    deck_t *hand;
    int ncoins;
};

#endif
