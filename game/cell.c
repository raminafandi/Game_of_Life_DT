#include "cell.h"

//Creating a new Cell
//Return Type:Cell
//Arguments: row and col (x,y)

Cell newCell(int row, int col)
{
    Cell cell;
    cell.row = row;
    cell.col = col;
    cell.isFull = 0;
    return cell;
}

//printing neighbours for testing purposes in initial stages
//Return Type: Void
//Arguments: Cell
void printNeighbours(Cell c)
{
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            printf("|%d %d|", c.row + i, c.col + j);
        }
        printf("\n");
    }
}