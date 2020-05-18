#include "gameplace.h"
#include "clipped.h"
#include "circular.h"

//creates new gameplace
//Return Type: Gameplace
//Arguments: rows,cols for the size of gameplace

Gameplace newgameplace(int rows, int cols)
{
    Gameplace gp;
    gp.nb_row = rows;
    gp.nb_col = cols;
    return gp;
}

//create new array of Cells in given gameplace
//Return Type: Cell 2d array
//Arguments: gameplace

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

//for printing coordinates of cells inside gameplace
//Return Type: Void
//Arguments: gameplace , cells as 2D array

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

//for printing cells are full or not inside gameplace
//Return Type: Void
//Arguments: gameplace , cells as 2D array

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

//Adds random full cells to the gameplace
//Return Type: Cell 2d array
//Arguments: gameplace , count of random full cells

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

// Play Game function : It takes the current Cell array and play one round
//depends on choices and returns the array again for next round
//Return Type: Cell 2d array
//Arguments: gameplace , cells as 2D array and choice of user

Cell **playGame(Gameplace gp, Cell **array, int choice)
{
    int size = gp.nb_row * gp.nb_col;
    Cell deletedCells[size];
    Cell addedCells[size];
    int index1 = 0;
    int index2 = 0;

    if (choice == 1)
    {
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
    }
    else
    {
        for (int i = 0; i < gp.nb_row; i++)
        {
            for (int j = 0; j < gp.nb_col; j++)
            {
                if (array[i][j].isFull == 1)
                {
                    if (checkFullCellDeadorAlive_Circular(gp, array, i, j).col >= 0 && checkFullCellDeadorAlive_Circular(gp, array, i, j).row >= 0)
                        deletedCells[index1++] = checkFullCellDeadorAlive_Circular(gp, array, i, j);
                }
                else
                {
                    if (checkEmptyCellDeadorAlive_Circular(gp, array, i, j).col >= 0 && checkEmptyCellDeadorAlive_Circular(gp, array, i, j).row >= 0)
                        addedCells[index2++] = checkEmptyCellDeadorAlive_Circular(gp, array, i, j);
                }
            }
        }
    }
    //printf("Deleted Cells\n");
    for (int i = 0; i < index1; i++)
    {
        //printf("[ %d %d ]\n", deletedCells[i].row, deletedCells[i].col);
        array[deletedCells[i].row][deletedCells[i].col].isFull = 0;
    }

    // printf("Added Cells\n");
    for (int i = 0; i < index2; i++)
    {
        //printf("[ %d %d ]\n", addedCells[i].row, addedCells[i].col);
        array[addedCells[i].row][addedCells[i].col].isFull = 1;
    }
    // printf("---------------\n");

    return array;
}
