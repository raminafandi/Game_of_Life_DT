#include <stdio.h>
#include <stdlib.h>
#include "gameplace.h"
#include "console.h"
#include "sdl2.h"

int main(int argc, char const *argv[])
{
    int choice;
    printf("Do you want to display in Console => 1 or SDL2 => 2?\n");
    scanf("%d",&choice);


    if(choice == 1)
   	    printInConsole();
    else{
        printInSDL();
    }



    return 0;
}
