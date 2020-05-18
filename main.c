#include <stdio.h>
#include <stdlib.h>
#include "gameplace.h"
#include "console.h"
#include "sdl2.h"

int main(int argc, char const *argv[])
{
    int choice;
    //Taking choice as input
    printf("Do you want to display in Console => 1 or SDL2 => 2?\n");
    scanf("%d", &choice);

    //choice 1 is for displaying in console
    if (choice == 1)
        printInConsole();
    //choice 2 is for displaying with help of SDL2
    else
    {
        printInSDL();
    }

    return 0;
}
