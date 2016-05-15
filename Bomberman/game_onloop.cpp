#include"game.h"

void game::OnLoop()
{
    bomb_manager->BurnFuses();
    explosion_manager->Update();
    enemy->Update(level);
    bomberman->Update();
}
