#include "Bomb.h"

#include <iostream>

Bomb::Bomb(unsigned int fuse_duration,
             SDL_Texture* texture,
             unsigned int x,
             unsigned int y,
             unsigned int bomb_size)
    :   m_timer(),
        m_fuse_duration(fuse_duration),
        m_texture(texture),
        m_explode(false),
        m_x(x),
        m_y(y),
        m_draw_size(bomb_size)
{
}

/*
Bomb::~Bomb()
{
}
*/

void Bomb::UpdateFuse()
{
    if (m_timer.getTimeElapsed() > m_fuse_duration)
        m_explode = true;
}

bool Bomb::Explode()
{
    return m_explode;
}

void Bomb::Draw(SDL_Renderer* renderer)
{
    SDL_Rect SrcR;
    SDL_Rect DestR;

    SrcR.x = 0;
    SrcR.y = 0;
    SrcR.w = 32;
    SrcR.h = 32;

    DestR.x = m_x;
    DestR.y = m_y;
    DestR.w = m_draw_size;
    DestR.h = m_draw_size;

    SDL_RenderCopy(renderer, m_texture, &SrcR, &DestR);
}

void Bomb::DEBUG_ShowTimer()
{
    std::cout << m_timer.getTimeElapsed() << std::endl;
}
