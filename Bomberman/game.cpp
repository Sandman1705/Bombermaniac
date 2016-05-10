#include"game.h"

game::game()
{
    window = NULL;
    Running = true;
    level = nullptr;
    explosion_manager = nullptr;
    bomb_manager = nullptr;
    bomberman = nullptr;
}

int game::OnExecute()
{
    if(OnInit() == false)
    {
        return -1;
    }

    if (LoadContent() == false)
    {
        return -1;
    }

    while(Running)
    {
        while(SDL_PollEvent(&Event))
        {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();

        SDL_Delay(100);
    }

    Cleanup();

    return 0;
}

int main(int argc, char* argv[])
{
    game theGame;

    return theGame.OnExecute();
}
