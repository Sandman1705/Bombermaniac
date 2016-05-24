#include "game.h"

game::game()
    : Running(true),
      window(nullptr),
      renderer(nullptr),
      Event(),
      keyboard_input(KeyboardInput::Instance()),
      texture(nullptr)
{

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
    }

    Cleanup();

    return 0;
}

int main(int argc, char* argv[])
{
    game theGame;

    return theGame.OnExecute();
}
