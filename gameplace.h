#ifndef GAMEPLACE
#define GAMEPLACE
typedef struct gameplace
{
    int nb_row;
    int nb_col;
} Gameplace;

Gameplace newgameplace(int rows, int cols);
#endif // !GAMEPLACE
