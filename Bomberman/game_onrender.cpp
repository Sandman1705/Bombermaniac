#include"game.h"
void game::OnRender()
{
    //Clear the renderer
    SDL_RenderClear(renderer);

    //Draw map and player
    level->Draw(renderer);
    //bomberman->Draw(renderer);

    //Update the screen
    SDL_RenderPresent(renderer);
}

