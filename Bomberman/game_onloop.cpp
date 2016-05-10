#include"game.h"

void game::OnLoop()
{
    bomb_manager->BurnFuses();
}
