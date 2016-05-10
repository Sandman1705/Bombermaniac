#include"game.h"

game::game()
{
    window = NULL;
    Running = true;
}

int game::OnExecute()
{
    if(OnInit() == false)
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
    }

    Cleanup();

    return 0;
}

int main(int argc, char* argv[])
{
    game theGame;

    return theGame.OnExecute();
}
