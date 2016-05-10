#include"game.h"

void game::Cleanup()
{
    delete level;
    delete bomberman;

    for (auto i=textures.begin(); i!=textures.cend(); ++i)
        SDL_DestroyTexture(*i);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
