#include"game.h"

bool game::OnInit()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }

    //win = SDL_CreateWindow("Image Loading", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
     if((window = SDL_CreateWindow("SDL Render Clear",100,100,640, 480, SDL_WINDOW_SHOWN)) == NULL) {
        return false;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL){
        cout << SDL_GetError() << endl;
        return 1;
    }
    return true;
}
