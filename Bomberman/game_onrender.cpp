#include"game.h"

void game::OnRender()
{
    //Clear the renderer
    SDL_RenderClear(renderer);

    //Draw
    level->Draw(renderer);
    bomb_manager->Draw(renderer);
    enemy_manager->Draw(renderer);
    bomberman->Draw(renderer);
    explosion_manager->Draw(renderer);

    //Update the screen
    SDL_RenderPresent(renderer);
}

