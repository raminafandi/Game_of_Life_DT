#include"sdl2.h"

#define HEIGHT 800
#define WIDTH 1000

void printInSDL()
{

    Gameplace gp = newgameplace(20, 20);

    Cell **arrcell = addRandomFullCells(gp, 80);

    printf("Clipped=1   or Circular=2\n");
    int choice;
    scanf("%d", &choice);

    SDL_Window* window = NULL;
        window = SDL_CreateWindow
        (
            "Game Of Life", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            WIDTH,
            HEIGHT,
            SDL_WINDOW_SHOWN
        );

        // Setup renderer
    SDL_Renderer* renderer = NULL;
        renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

    SDL_RenderClear( renderer );

    bool quit = false;
	while (!quit)
	{
		SDL_Event event;

		while (!quit && SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			}
		}

        int myW = WIDTH / gp.nb_row;
        int myH = HEIGHT / gp.nb_col;

        while(1)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	        SDL_RenderClear(renderer);

	        SDL_SetRenderDrawColor(renderer, 0,0,0,0);

            for(int i=0; i<gp.nb_row; ++i)
            {
                for(int j= 0; j<gp.nb_col; ++j)
                    if(arrcell[i][j].isFull == 1)
                    {
                        SDL_Rect rect;
                        rect.h = myH;
                        rect.w = myW;
                        rect.x = i*myW;
                        rect.y = j*myH;
                        SDL_RenderFillRect(renderer,&rect);
                    }      
            }
            
            SDL_RenderPresent(renderer);   
            SDL_Delay(100);
            arrcell = playGame(gp,arrcell,choice);
        }

        // MOUSE INTERACTION
        int x,y;
        if ( SDL_GetMouseState(&x,&y) & SDL_BUTTON(SDL_BUTTON_LEFT) ) // one & it is for bits AND
        {
            // USE COLOR
            SDL_SetRenderDrawColor(renderer, 255,0,0,0);
            SDL_RenderDrawPoint(renderer,x,y);
        }
        
    }

	SDL_Quit();
}