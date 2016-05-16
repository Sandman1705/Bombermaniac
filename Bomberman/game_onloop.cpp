#include"game.h"

void game::OnLoop()
{
    bomb_manager->Update();
    explosion_manager->Update();
    if(player_manager->Get_player()!=nullptr)
        enemy_manager->Update();
    else
        delete enemy_manager;
    player_manager->Update();
}
