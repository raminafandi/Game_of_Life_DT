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

Cell **playGame(Gameplace gp, Cell **array)
{
    int size = gp.nb_row * gp.nb_col;
    Cell deletedCells[size];
    Cell addedCells[size];
    int index1 = 0;
    int index2 = 0;

    for (int i = 0; i < gp.nb_row; i++)
    {
        for (int j = 0; j < gp.nb_col; j++)
        {
            if (array[i][j].isFull == 1)
            {
                if (checkFullCellDeadorAlive(gp, array, i, j).col >= 0 && checkFullCellDeadorAlive(gp, array, i, j).row >= 0)
                    deletedCells[index1++] = checkFullCellDeadorAlive(gp, array, i, j);
            }
            else
            {
                if (checkEmptyCellDeadorAlive(gp, array, i, j).col >= 0 && checkEmptyCellDeadorAlive(gp, array, i, j).row >= 0)
                    addedCells[index2++] = checkEmptyCellDeadorAlive(gp, array, i, j);
            }
        }
    }
    /// printf("Deleted Cells\n");
    for (int i = 0; i < index1; i++)
    {
        //  printf("%d %d\n", deletedCells[i].row, deletedCells[i].col);
        array[deletedCells[i].row][deletedCells[i].col].isFull = 0;
    }

    //  printf("Added Cells\n");
    for (int i = 0; i < index2; i++)
    {
        // printf("%d %d\n", addedCells[i].row, addedCells[i].col);
        array[addedCells[i].row][addedCells[i].col].isFull = 1;
    }
    // printf("---------------\n");

    return array;
}
