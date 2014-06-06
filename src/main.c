#include "coup.h"

#include <stdio.h>

int
main(
    int argc,
    char *argv[])
{
    coup_t *coup = coup_newgame(4);
    if (!coup)
    {
        printf("failed\n");
    }
    return 0;
}
