#include "console.h"
void printInConsole()
{
    Gameplace gp = newgameplace(20, 20);

    Cell **arrcell = addRandomFullCells(gp, 80);
    //chosing either clipped version of game will be playing or circular
    printf("Clipped=1   or Circular=2\n");
    int choice;
    scanf("%d", &choice);

    while (1)
    {
        printf("\033[2J");
        // hide cursor
        printf("\033[?25l");
        // goto 0,0
        for (int i = 0; i < gp.nb_row; ++i) //printing in color
        {
            printf("\033[%d;4H", i + 2);
            for (int j = 0; j < gp.nb_col; ++j)
            {
                int c = arrcell[i][j].isFull == 1 ? 104 : 40;
                printf("\033[%dm  ", c);
                // draw 2 space with color 40 or 101 (black or magenta)
            }
        }
        arrcell = playGame(gp, arrcell, choice);
        //show cursor
        printf("\033[?25h");
        sleep(1);
        printf("\n");
    }
}