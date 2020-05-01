#include "gameplace.h"

Gameplace newgameplace(int rows, int cols)
{
    Gameplace gp;
    gp.nb_row = rows;
    gp.nb_col = cols;
    return gp;
}