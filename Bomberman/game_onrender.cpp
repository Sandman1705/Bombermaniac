#include"game.h"
void game::OnRender()
{
    const int SHAPE_SIZE = 32;

    SDL_Rect SrcR;
    SDL_Rect DestR;

    SrcR.x = 0;
    SrcR.y = 0;
    SrcR.w = SHAPE_SIZE;
    SrcR.h = SHAPE_SIZE;

    DestR.x = 0;
    DestR.y = 0;
    DestR.w = SHAPE_SIZE;
    DestR.h = SHAPE_SIZE;

    //First clear the renderer
    SDL_RenderClear(renderer);
    for (unsigned i = 0; i < level->Get_height(); ++i)
    {
        for (unsigned j = 0; j < level->Get_width(); ++j)
        {
            DestR.y = SHAPE_SIZE*i;
            DestR.x = SHAPE_SIZE*j;
            //Draw the texture
            //std::cout << i << ":" << j << "=" << level->m_layout[i][j] << std::endl;
            SDL_Texture *tex = textures[ level->m_layout[i][j] ];
            SDL_RenderCopy(renderer, tex, &SrcR, &DestR);
        }

    }

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

