#ifndef CIRCULAR
#define CIRCULAR
#include <stdio.h>
#include <stdlib.h>
#include "cell.h"
#include "gameplace.h"

Cell checkFullCellDeadorAlive_Circular(Gameplace gp, Cell **array, int z, int k);
Cell checkEmptyCellDeadorAlive_Circular(Gameplace gp, Cell **array, int z, int k);
#endif