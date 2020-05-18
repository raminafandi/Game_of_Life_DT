#include "circular.h"

//Basicly for checking a full cell dead or alive in next round with checking its neighbor cells in circular configuration
//Return Type:Cell
//Arguments: gameplace , all cells as array , position of cell as (x,y)

Cell checkFullCellDeadorAlive_Circular(Gameplace gp, Cell **array, int z, int k)
{
    int index = 0;                // a counter for counting how much neighbor cell is full
    for (int i = -1; i <= 1; i++) //for checking neighbours (z-1 ,k) (z,k) (z+1,k)
    {
        for (int j = -1; j <= 1; j++) //for checking neighbours (z,k+1) (z,k) (z,k+1)
        {
            int neigh_row = z + i;
            int neigh_col = k + j;
            //cases when neighbours is in other side of panel (circular case)
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
            //case when neighbor's coordinates equals the cells itself

            else if (neigh_row == z && neigh_col == k)
            {
                continue;
            }

            //case when neighbor is full and index increments by 1
            else if (array[neigh_row][neigh_col].isFull == 1)
            {
                index++;
            }
        }
    }
    //if index equals 3 or 2 cell doesn't die in next round so returns newCell(-1,-1), else it returns the cell
    return index == 3 || index == 2 ? newCell(-1, -1) : array[z][k];
}

//Basicly for checking an empty cell dead or alive in next round with checking its neighbor cells
//Return Type:Cell
//Arguments: gameplace , all cells as array , position of cell as (x,y)

Cell checkEmptyCellDeadorAlive_Circular(Gameplace gp, Cell **array, int z, int k)
{
    int index = 0;                // a counter for counting how much neighbor cell is full
    for (int i = -1; i <= 1; i++) //for checking neighbours (z-1 ,k) (z,k) (z+1,k)
    {
        for (int j = -1; j <= 1; j++) //for checking neighbours (z,k+1) (z,k) (z,k+1)
        {
            int neigh_row = z + i;
            int neigh_col = k + j;
            //cases when neighbours is in other side of panel (circular case)
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
            //case when neighbor's coordinates equals the cells itself

            else if (neigh_row == z && neigh_col == k)
            {
                continue;
            }
            //case when neighbor is full and index increments by 1

            else if (array[neigh_row][neigh_col].isFull == 1)
            {
                index++;
            }
        }
    }
    //if index equals 3 cell lives in next round so returns cell, else it returns the newCell(-1,-1) dying cell

    return (index == 3) ? array[z][k] : newCell(-1, -1);
}