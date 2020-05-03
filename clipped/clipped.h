#ifndef CLIPPED
#define CLIPPED
#include <stdio.h>
#include <stdlib.h>
#include "cell.h"
#include "gameplace.h"

Cell checkFullCellDeadorAlive(Gameplace gp, Cell **array, int z, int k);
Cell checkEmptyCellDeadorAlive(Gameplace gp, Cell **array, int z, int k);
#endif