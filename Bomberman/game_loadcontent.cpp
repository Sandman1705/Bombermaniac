#include"game.h"

bool game::LoadContent()
{
    level = new Map(20,15);
    level->loadLayout();

    for (auto i = resourcesPaths.cbegin(); i != resourcesPaths.cend(); ++i)
    {
        SDL_Surface *bmp = SDL_LoadBMP((*i).c_str());
        if (bmp == nullptr){
            std::cout << "Failed to load: " << (*i).c_str() << std::endl;
            return false;
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


    return true;
}

bool game::GetResourcesPaths()
{
    resourcesPaths.push_back("resources\\yellow.bmp");
    resourcesPaths.push_back("resources\\blue.bmp");
    resourcesPaths.push_back("resources\\red.bmp");
    resourcesPaths.push_back("resources\\green.bmp");
    //std::cout << "Loaded resources file paths" << std::endl;
    return true;
}
