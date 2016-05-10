#include"game.h"

void game::OnEvent(SDL_Event* Event)
{
    if(Event->type == SDL_QUIT)
    {
        Running = false;
    }
}
