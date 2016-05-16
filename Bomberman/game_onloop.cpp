#include"game.h"

void game::OnLoop()
{
    bomb_manager->Update();
    explosion_manager->Update();
    enemy_manager->Update();
    player_manager->Update();
}
