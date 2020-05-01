#ifndef GAMEPLACE
#define GAMEPLACE

#include <stdio.h>
#include <stdlib.h>
#include "cell.h"

typedef struct gameplace
{
    int nb_row;
    int nb_col;
} Gameplace;

Gameplace newgameplace(int rows, int cols);
Cell **createCells(Gameplace gp);
void printGameplace(Gameplace gp, Cell **array);
void printGameplaceFull(Gameplace gp, Cell **array);
Cell **addRandomFullCells(Gameplace gp, int count);
#endif // !GAMEPLACE
