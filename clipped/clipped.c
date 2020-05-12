#include "clipped.h"
Cell checkFullCellDeadorAlive(Gameplace gp, Cell **array, int z, int k)
{
    int index = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int neigh_row = z + i;
            int neigh_col = k + j;
            if (neigh_col < 0 || neigh_row < 0 || neigh_col >= gp.nb_col || neigh_row >= gp.nb_row)
            {
                continue;
            }
            else if (neigh_row == z && neigh_col == k)
            {
                continue;
            }
            else if (array[neigh_row][neigh_col].isFull == 1)
            {
                index++;
            }
        }
    }

    return index == 3 || index == 2 ? newCell(-1, -1) : array[z][k];
}

Cell checkEmptyCellDeadorAlive(Gameplace gp, Cell **array, int z, int k)
{
    int index = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int neigh_row = z + i;
            int neigh_col = k + j;
            if (neigh_col < 0 || neigh_row < 0 || neigh_col >= gp.nb_col || neigh_row >= gp.nb_row)
            {
                continue;
            }
            if (neigh_row == z && neigh_col == k)
            {
                continue;
            }
            if (array[neigh_row][neigh_col].isFull == 1)
            {
                index++;
            }
        }
    }

    return (index == 3) ? array[z][k] : newCell(-1, -1);
}