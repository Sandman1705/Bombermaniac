#include"game.h"

void game::OnLoop()
{
    bomb_manager->BurnFuses();
    explosion_manager->Update();
    enemy->update(level);
    bomberman->update();
}
