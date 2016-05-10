#include "Bomb.h"

#include <iostream>

Bomb::Bomb(unsigned int fuse_duration,
             SDL_Texture* texture,
             SDL_Rect* SrcR,
             unsigned int x,
             unsigned int y,
             unsigned int bomb_size)
    :   m_timer(),
        m_fuse_duration(fuse_duration),
        m_texture(texture),
        m_SrcR(SrcR),
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

void Bomb::BurnFuse()
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
    SDL_Rect DestR;

    DestR.x = m_x;
    DestR.y = m_y;
    DestR.w = m_draw_size;
    DestR.h = m_draw_size;

    SDL_RenderCopy(renderer, m_texture, m_SrcR, &DestR);
}

void Bomb::DEBUG_ShowTimer()
{
    std::cout << m_timer.getTimeElapsed() << std::endl;
}
