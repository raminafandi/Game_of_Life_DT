#ifndef CIRCULAR
#define CIRCULAR
#include <stdio.h>
#include <stdlib.h>
#include "cell.h"
#include "gameplace.h"

Cell checkFullCellDeadorAlive2(Gameplace gp, Cell **array, int z, int k);
Cell checkEmptyCellDeadorAlive2(Gameplace gp, Cell **array, int z, int k);
#endif