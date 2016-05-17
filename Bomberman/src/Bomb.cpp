#include "Bomb.h"

#ifdef DEBUG_OUTPUT_BOMB
#include <iostream>
#endif // DEBUG_OUTPUT_BOMB

Bomb::Bomb(unsigned int fuse_duration,
           SDL_Texture* texture,
           SDL_Rect* SrcR,
           unsigned int x,
           unsigned int y,
           unsigned int bomb_size,
           double intensity
          )
    :   m_timer(),
        m_fuse_duration(fuse_duration),
        m_texture(texture),
        m_SrcR(SrcR),
        m_explode(false),
        m_x(x),
        m_y(y),
        m_draw_size(bomb_size),
        m_intensity(intensity)
{
    #ifdef DEBUG_OUTPUT_BOMB
    std::cout << "Bomb placed: X:" << m_x << " Y:" << m_y << " fuse:" << m_fuse_duration << " intesity:" << m_intensity << std::endl;
    #endif // DEBUG_OUTPUT_BOMB
}

#ifdef DEBUG_OUTPUT_BOMB
Bomb::~Bomb()
{
    std::cout << "Bomb destroyed: X:" << m_x << " Y:" << m_y << " fuse:" << m_fuse_duration << " intesity:" << m_intensity << std::endl;
}
#endif // DEBUG_OUTPUT_BOMB


void Bomb::Update()
{
    if (m_timer.GetTimeElapsed() > m_fuse_duration)
        m_explode = true;
}

bool Bomb::Explode() const
{
    return m_explode;
}

void Bomb::Draw(SDL_Renderer* renderer) const
{
    SDL_Rect DestR;

    DestR.x = m_x;
    DestR.y = m_y;
    DestR.w = m_draw_size;
    DestR.h = m_draw_size;

    SDL_RenderCopy(renderer, m_texture, m_SrcR, &DestR);
}
