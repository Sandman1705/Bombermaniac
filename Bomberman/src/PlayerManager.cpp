#include "PlayerManager.h"
#include <iostream>
PlayerManager::PlayerManager(SDL_Texture* texture, unsigned int tile_size, BombManager *bomb_manager,
               KeyboardInput *keyboard_input, Map *level)
{
    m_texture = texture;
    m_tile_size = tile_size;
    m_bomb_manager = bomb_manager;
    m_keyboard_input = keyboard_input;
    m_level = level;
    m_timer.ResetTimer();
}

void PlayerManager::MakePlayer(unsigned int x, unsigned int y)
{
    m_player = new Player(m_texture, m_tile_size, m_bomb_manager, m_keyboard_input, m_level, x, y);
}

void PlayerManager::Draw(SDL_Renderer* renderer)
{
    if(m_player->Get_health() == 0 && m_alive)
    {
        m_alive = 0;
        m_timer.ResetTimer();
    }

    if(m_alive == 0 && m_timer.GetTimeElapsed() >= 2000)
    {
        m_alive = 1;
        m_player->Set_health(100);
    }


    //main condition
    if(m_alive != 0)
    {
        m_player->Draw(renderer);
    }
}

void PlayerManager::Update()
{
    m_player->Update();
}

Player* PlayerManager::Get_player() const
{
    return m_player;
}
