#ifndef CELL
#define CELL
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct cell
{
    int row;
    int col;
    int isFull;
} Cell;

Cell newCell(int row, int col);
void printNeighbours(Cell c);

#endif