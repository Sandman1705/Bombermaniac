#include"game.h"

void game::Cleanup()
{
    delete level;
    delete bomberman;
    delete bomb_manager;
    delete enemy;

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
