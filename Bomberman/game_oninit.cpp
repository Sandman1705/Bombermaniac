#include "game.h"

#define DEBUG_OUTPUT_GAME

#ifdef DEBUG_OUTPUT_GAME
#include <iostream>
#endif // DEBUG_OUTPUT_GAME

bool game::OnInit()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        #ifdef DEBUG_OUTPUT_GAME
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        #endif // DEBUG_OUTPUT_GAME
        return false;
    }
    /* TTF Init */
    if (TTF_Init() != 0){
        #ifdef DEBUG_OUTPUT_GAME
		std::cout << "TTF_Init Error: " << SDL_GetError() << std::endl;
        #endif // DEBUG_OUTPUT_GAME
		SDL_Quit();
		return 1;
	}
    /* SDL Window */
    if((window = SDL_CreateWindow("SUPER ULTRA MEGA BOMBERMAN",100,100, window_width, window_height, SDL_WINDOW_SHOWN)) == NULL)
    {
        #ifdef DEBUG_OUTPUT_GAME
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        #endif // DEBUG_OUTPUT_GAME
        //SDL_Quit();
        return false;
    }
    /* SDL Renderer */
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL){
        #ifdef DEBUG_OUTPUT_GAME
        std::cout << SDL_GetError() << std::endl;
        #endif // DEBUG_OUTPUT_GAME
        return false;
    }

    return true;
}
