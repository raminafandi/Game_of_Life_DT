#include "circular.h"
Cell checkFullCellDeadorAlive2(Gameplace gp, Cell **array, int z, int k)
{
    int index = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int neigh_row = z + i;
            int neigh_col = k + j;
            if (neigh_col < 0 || neigh_row < 0 || neigh_row == gp.nb_row || neigh_col == gp.nb_col)
            {
                int x = neigh_row;
                int y = neigh_col;

                if (neigh_row < 0)
                {
                    x = neigh_row + gp.nb_row;
                }
                else if (neigh_row == gp.nb_row)
                {
                    x = neigh_row - gp.nb_row;
                }

                if (neigh_col < 0)
                {
                    y = neigh_col + gp.nb_col;
                }
                else if (neigh_col == gp.nb_col)
                {
                    y = neigh_col - gp.nb_col;
                }
                if (array[x][y].isFull == 1)
                {
                    index++;
                }
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

Cell checkEmptyCellDeadorAlive2(Gameplace gp, Cell **array, int z, int k)
{
    int index = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int neigh_row = z + i;
            int neigh_col = k + j;

            if (neigh_col < 0 || neigh_row < 0 || neigh_row == gp.nb_row || neigh_col == gp.nb_col)
            {
                int x = neigh_row;
                int y = neigh_col;

                if (neigh_row < 0)
                {
                    x = neigh_row + gp.nb_row;
                }
                else if (neigh_row == gp.nb_row)
                {
                    x = neigh_row - gp.nb_row;
                }

                if (neigh_col < 0)
                {
                    y = neigh_col + gp.nb_col;
                }
                else if (neigh_col == gp.nb_col)
                {
                    y = neigh_col - gp.nb_col;
                }
                if (array[x][y].isFull == 1)
                {
                    index++;
                }
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

    return (index == 3) ? array[z][k] : newCell(-1, -1);
}