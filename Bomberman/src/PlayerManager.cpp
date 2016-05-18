#include "PlayerManager.h"
#include <iostream>
PlayerManager::PlayerManager(SDL_Texture* texture, unsigned int tile_size, Relay *relay,
               KeyboardInput *keyboard_input)
{
    m_texture = texture;
    m_tile_size = tile_size;
    m_relay = relay;
    m_keyboard_input = keyboard_input;
    m_timer.ResetTimer();
}

void PlayerManager::MakePlayer(unsigned int x, unsigned int y)
{
    m_player = new Player(m_texture, m_tile_size, m_relay, m_keyboard_input, x, y);
}

void PlayerManager::KillPlayer(unsigned int x, unsigned int y, double intensity)
{
    EnemyDestroyer::DestroyPlayer(m_player, x, y, m_tile_size, intensity);
}

void PlayerManager::Draw(SDL_Renderer* renderer)
{
    if(m_player->Get_health() == 0 && m_alive)
    {
        m_alive = 0;
        m_lives--;
        m_timer.ResetTimer();

        if(m_lives == -1)
            m_lives = 3;
    }

    if(m_alive == 0 && m_timer.GetTimeElapsed() >= 2000)
    {
        m_alive = 1;
        m_player->Set_health(100);
    }

    //Draw number of lives
    SDL_Rect SrcR;
    SDL_Rect DestR;

    unsigned int SHAPE_SIZE_x = 12;
    unsigned int SHAPE_SIZE_y = 17;

    unsigned int source_x = 200;
    unsigned int source_y = 174;
    //unsigned int source_const = 4;
    //unsigned int texture_offset = source_const + SHAPE_SIZE_x + 2;

    SrcR.y = source_y;
    SrcR.w = SHAPE_SIZE_x;
    SrcR.h = SHAPE_SIZE_y;

    switch(m_lives)
    {
        case 0:
            SrcR.x = (m_lives)*SHAPE_SIZE_x + source_x;
        break;

        case 1:
            SrcR.x = (m_lives)*SHAPE_SIZE_x + source_x;
        break;

        case 2:
            SrcR.x = (m_lives)*SHAPE_SIZE_x + source_x;
        break;

        case 3:
            SrcR.x = (m_lives)*SHAPE_SIZE_x + source_x;
        break;
    }

    DestR.x = 0;
    DestR.y = 0;
    DestR.w = m_tile_size;
    DestR.h = m_tile_size;

    SDL_RenderCopy(renderer, m_texture, &SrcR, &DestR);

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
