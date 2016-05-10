#include"game.h"
#include"SDL_image.h"

bool game::LoadContent()
{
    level = new Map("resources\\levels\\level1.txt");


    for (auto i = resourcesPaths.cbegin(); i != resourcesPaths.cend(); ++i)
    {
        SDL_Surface *bmp = SDL_LoadBMP((*i).c_str());

        if(i == resourcesPaths.cend()-1) //Checking if image is player_move and removing background
        {
            SDL_SetColorKey(bmp, SDL_TRUE, SDL_MapRGB(bmp->format, 0, 0xFF, 0) );

            if (bmp == nullptr)
            {
                std::cout << "Failed to load: " << (*i).c_str() << std::endl;
                return false;
            }
        }
        else
        {
            if (bmp == nullptr)
            {
                std::cout << "Failed to load: " << (*i).c_str() << std::endl;
                return false;
            }
        }


        bmpFiles.push_back(bmp);
    }


    for (auto i = bmpFiles.begin(); i != bmpFiles.end(); ++i)
    {
        SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, *i);
        SDL_FreeSurface(*i);
        if (tex == nullptr){
            std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
            return false;
        }
        textures.push_back(tex);
    }

    bomberman = new player(textures[3]);

    return true;
}

bool game::GetResourcesPaths()
{
    resourcesPaths.push_back("resources\\green0.bmp");
    resourcesPaths.push_back("resources\\wall1.bmp");
    resourcesPaths.push_back("resources\\wall2.bmp");
    resourcesPaths.push_back("resources\\player_move.bmp");
    //resourcesPaths.push_back("resources\\player_move.png");
    //std::cout << "Loaded resources file paths" << std::endl;
    return true;
}
