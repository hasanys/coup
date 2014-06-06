#include "coup.h"
#include "carddeck.h"

#include <stdio.h>
#include <string.h>

struct coup_player {
    deck_t *hand;
    int ncoins;
};

struct coup {
    deck_t *court;
    deck_t *discard;

    int nplayers;
    struct coup_player *player;
};

coup_t *
coup_newgame(
    int nplayers)
{
    if (nplayers < COUP_MIN_PLAYERS || nplayers > COUP_MAX_PLAYERS)
    {
        return NULL;
    }

    /* Allocate memory for game */
    coup_t *coup = (coup_t*)malloc(sizeof(coup_t));
    if (!coup)
    {
        return NULL;
    }
    memset(coup, 0x00, sizeof(coup_t));

    /* Initialize court deck */
    deck_t *court = deck_alloc();
    deck_init(court);
    int i;
    for(i=0; i<3; i++)
    {
        deck_add_card(court, card_make("Captain", "\"Steal\" 2 coins from a player. Blocks Stealing."));
        deck_add_card(court, card_make("Ambassador", "\"Exchange\" 2 cards from the deck. Blocks Stealing."));
        deck_add_card(court, card_make("Duke", "\"Tax\" 3 coins. Blocks foreign aid."));
        deck_add_card(court, card_make("Contessa", "\"Block\" assassination."));
        deck_add_card(court, card_make("Assassin", "\"Assassinate\" a player for 3 coins."));
    }
    deck_shuffle(court);
    coup->court = court;

    /* Initialize discard deck */
    deck_t *discard = deck_alloc();
    deck_init(discard);
    coup->discard = discard;

    /* Initialize player data */
    coup->nplayers = nplayers;
    coup->player = (struct coup_player*)calloc(nplayers, sizeof(struct coup_player));
    if (!coup->player)
    {
        return NULL;
    }

    for(i=0; i<nplayers; i++)
    {
        struct coup_player *player = &coup->player[i];
        player->ncoins = COUP_START_COINS;
        player->hand = deck_alloc();
        deck_init(player->hand);
        card_t *card1 = deck_take_card(coup->court);
        card_t *card2 = deck_take_card(coup->court);
        deck_add_card(player->hand, card1);
        deck_add_card(player->hand, card2);
    }

    return coup;
}


