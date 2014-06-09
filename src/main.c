#include "coup.h"

#include <stdio.h>

void
game_over(
    coup_t *coup)
{
}

void
next_turn(
    coup_t *coup,
    struct coup_player *player)
{
}

int
main(
    int argc,
    char *argv[])
{
    coup_t *coup = coup_newgame(4, NULL);
    if (!coup)
    {
        printf("failed\n");
    }
    return 0;
}
