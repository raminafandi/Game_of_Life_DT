#ifndef CELL
#define CELL

typedef struct cell
{
    int row;
    int col;
    int isFull;
} Cell;

Cell newCell(int row, int col);
void printNeighbours(Cell c);

#endif