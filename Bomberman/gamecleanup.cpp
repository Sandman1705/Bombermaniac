#include"game.h"

void game::Cleanup()
{
    delete level;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
