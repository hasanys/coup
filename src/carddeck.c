#include "carddeck.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card {
    const char *name;
    const char *description;

    /* For card lists */
    struct card *next;
};

struct deck {
    int ncards;
    struct card *top;
};

card_t *
card_make(
    const char *name,
    const char *description)
{
    card_t *card = malloc(sizeof(card_t));
    card->name = name;
    card->description = description;
    return card;
}

const char *
card_name(
    card_t *card)
{
    return card->name;
}

const char *
card_description(
    card_t *card)
{
    return card->description;
}

deck_t *
deck_alloc()
{
    return (deck_t*)malloc(sizeof(deck_t));
}

int
deck_init(
    deck_t *deck)
{
    if (!deck)
    {
        return -1;
    }

    deck->ncards = 0;
    deck->top = NULL;

    struct timespec t;
    clock_gettime(CLOCK_REALTIME, &t);
    srand(t.tv_nsec);

    return 0;
}

card_t *
deck_take_card(
    deck_t *deck)
{
    if (!deck)
    {
        return NULL;
    }

    if (deck->top)
    {
        card_t *return_card = deck->top;
        deck->top = deck->top->next;
        deck->ncards--;
        return_card->next = NULL;
        return return_card;
    }else{
        return NULL;
    }
}

int
deck_add_card(
    deck_t *deck,
    card_t *card)
{
    if (!deck || !card)
    {
        return -1;
    }

    card->next = NULL;

    if (!deck->top)
    {
        deck->top = card;
        deck->ncards++;
        return 0;
    }

    card_t *card_iter = deck->top;
    while(card_iter)
    {
        if (!card_iter->next)
        {
            card_iter->next = card;
            deck->ncards++;
            return 0;
        }

        card_iter = card_iter->next;
    }

    return -1;
}

int
deck_shuffle(
    deck_t *deck)
{
    if (!deck)
    {
        return -1;
    }

    int i;
    for(i=0; i<3000; i++)
    {
        card_t *card = deck->top;
        card_t *last_card = NULL;
        int a = rand() % deck->ncards;

        for(; a>0; a--)
        {
            last_card = card;
            card = card->next;
        }

        if (!card)
        {
            return -1;
        }

        /* Take card from deck */
        if (last_card)
        {
            last_card->next = card->next;
            deck->ncards--;
        }else{
            deck->top = deck->top->next;
            deck->ncards--;
        }

        /* Put back in deck */
        deck_add_card(deck, card);
    }

    return 0;
}

void
deck_list(
    deck_t *deck)
{
    if (!deck)
    {
        printf("(null)\n");
        return;
    }

    if (!deck->top)
    {
        printf("Empty.\n");
        return;
    }

    card_t *card = deck->top;
    while(card)
    {
        printf("%s \"%s\"\n", card_name(card), card_description(card));
        card = card->next;
    }
}
