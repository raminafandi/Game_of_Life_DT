#include "gameplace.h"

Gameplace newgameplace(int rows, int cols)
{
    Gameplace gp;
    gp.nb_row = rows;
    gp.nb_col = cols;
    return gp;
}

Cell **createCells(Gameplace gp)
{
    int size = gp.nb_row * gp.nb_col;
    Cell **array = (Cell **)malloc(gp.nb_col * sizeof(Cell *));

    for (int z = 0; z < size; z++)
    {
        array[z] = (Cell *)malloc(gp.nb_row * sizeof(Cell));
    }

    for (int i = 0; i < gp.nb_row; i++)
    {
        for (int j = 0; j < gp.nb_col; j++)
        {
            array[i][j] = newCell(i, j);
        }
    }

    return array;
}

void printGameplace(Gameplace gp, Cell **array)
{
    for (int i = 0; i < gp.nb_row; i++)
    {
        for (int j = 0; j < gp.nb_col; j++)
        {
            printf("|%d %d|", array[i][j].row, array[i][j].col);
        }
        printf("\n");
    }
}

void printGameplaceFull(Gameplace gp, Cell **array)
{
    for (int i = 0; i < gp.nb_row; i++)
    {
        for (int j = 0; j < gp.nb_col; j++)
        {
            printf("|%d|", array[i][j].isFull);
        }
        printf("\n");
    }
}

Cell **addRandomFullCells(Gameplace gp, int count)
{
    srand(time(NULL));
    Cell **arrcell = createCells(gp);

    for (int i = 0; i < count; i++)
    {
        int row = rand() % gp.nb_row;
        int col = rand() % gp.nb_col;
        arrcell[row][col].isFull = 1;
    }

    return arrcell;
}