#include "game.h"
#include "SDL_image.h"
#include "Display/DisplayManager.h"
#include "Constants/ResourcesConstants.h"

#ifdef DEBUG_OUTPUT_GAME
#include <iostream>
#endif // DEBUG_OUTPUT_GAME

bool game::LoadContent()
{
    /* Texture loading - Begin */

    std::string resourcesPath = RESOURCES_BASE_PATH + RESOURCES_TEXTURES;

    SDL_Surface *bmp = SDL_LoadBMP(resourcesPath.c_str());

    if (bmp == nullptr)
    {
        #ifdef DEBUG_OUTPUT_GAME
        std::cout << "Failed to load: " << resourcesPath.c_str() << std::endl;
        #endif // DEBUG_OUTPUT_GAME
        return false;
    }

    // Texture transparency settings //
    SDL_SetColorKey(bmp, SDL_TRUE, SDL_MapRGB(bmp->format, 0, 0xC0, 0xC0) );

    texture = SDL_CreateTextureFromSurface(renderer, bmp);
    SDL_FreeSurface(bmp);
    if (texture == nullptr){
        #ifdef DEBUG_OUTPUT_GAME
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        #endif // DEBUG_OUTPUT_GAME
        return false;
    }
    /* Texture loading - End */

    /* Game objects initializing - Begin */
    //keyboard_input = KeyboardInput::Instance();

    display_manager = new DisplayManager(texture,renderer,&Running,window_width,window_height);

    //GameDisplay* game_display = new GameDisplay(texture,keyboard_input);
    //game_display->Init();

//    WelcomeDisplay* welcome_display = new WelcomeDisplay(texture,keyboard_input);
//    ExitDisplay* exit_display = new ExitDisplay(&Running);

    //display = game_display;
    /* Game objects initializing - End */

    return true;
}
