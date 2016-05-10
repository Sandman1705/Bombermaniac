#include"game.h"
void game::OnRender()
{
    const int SHAPE_SIZE = level->Get_tile_size();

    SDL_Rect SrcR;
    SDL_Rect DestR;

    //First clear the renderer
    SDL_RenderClear(renderer);

    level->Draw(renderer,&textures);

    //Cropping players image: 7px on sides, 5px top and bottom
    SrcR.x = 7;
    SrcR.y = 5;
    SrcR.w = SHAPE_SIZE-14;
    SrcR.h = SHAPE_SIZE-10;
    //----------------------
    DestR.x = bomberman->Get_x();
    DestR.y = bomberman->Get_y();
    DestR.w = 17;
    DestR.h = 23;
    //----------------------

    SDL_Texture *tex = textures[3];
    SDL_RenderCopy(renderer, tex, &SrcR, &DestR);

    //Update the screen
    SDL_RenderPresent(renderer);
}

