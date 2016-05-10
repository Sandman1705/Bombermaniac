#include"game.h"

void game::Cleanup()
{
    delete level;
    delete bomb_manager;
    delete explosion_manager;
    delete bomberman;
    delete enemy;

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
