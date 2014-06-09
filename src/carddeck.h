#ifndef __CARDDECK_H__
#define __CARDDECK_H__

typedef struct card card_t;
typedef struct deck deck_t;

card_t *card_make(const char *name, const char *description);
const char *card_name(card_t *card);
const char *card_description(card_t *card);

deck_t *deck_alloc();
int deck_init(deck_t *deck);
card_t *deck_take_card(deck_t *deck);
int deck_add_card(deck_t *deck, card_t *card);
int deck_shuffle(deck_t *deck);
void deck_list(deck_t *deck);
int deck_count(deck_t *deck);

#endif
