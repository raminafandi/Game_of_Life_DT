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
Cell checkFullCellDeadorAlive(Gameplace gp, Cell **array, int z, int k);
Cell checkEmptyCellDeadorAlive(Gameplace gp, Cell **array, int z, int k);
Cell **playGame(Gameplace gp, Cell **array, int choice);
#endif // !GAMEPLACE
