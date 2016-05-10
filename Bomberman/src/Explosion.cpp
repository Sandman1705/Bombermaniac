#include "Explosion.h"

Explosion::Explosion(unsigned int duration,
                     unsigned int x_center,
                     unsigned int y_center,
                     double intensity,
                     unsigned int tile_size,
                     SDL_Texture* texture,
                     SDL_Rect*  start_SrcR)
    :   m_timer(),
        m_duration(duration),
        m_exploding(true),
        m_x_center(x_center),
        m_y_center(y_center),
        m_intensity(intensity),
        m_tile_size(tile_size),
        m_texture(texture),
        m_start_SrcR(start_SrcR),
        m_phase_number(0)
{
    #ifdef DEBUG_OUTPUT
    std::cout << "Start of explosion: X:" << m_x_center << " Y:" << m_y_center << std::endl;
    #endif // DEBUG_OUTPUT
}

void Explosion::Update()
{
    if (m_timer.getTimeElapsed() > m_duration)
        m_exploding = false;
    else
    {
        m_phase_number =  m_timer.getTimeElapsed() / (m_duration / NUMBER_OF_PHASES); // timeElapsed / phaseLength
        #ifdef DEBUG_OUTPUT
        std::cout << "Explosion: X:" << m_x_center << " Y:" << m_y_center << " Phase:" << m_phase_number << std::endl;
        #endif // DEBUG_OUTPUT
    }
}

bool Explosion::IsExploding()
{
    return m_exploding;
}

void Explosion::Draw(SDL_Renderer* renderer)
{
    SDL_Rect SrcR;
    SDL_Rect DestR;
    unsigned int explosion_size = m_tile_size * m_intensity;

    SrcR.x = m_start_SrcR->x + 100 * (m_phase_number % 9) ;
    SrcR.y = m_start_SrcR->y + 100 * (m_phase_number / 9) ;
    SrcR.w = m_start_SrcR->w;
    SrcR.h = m_start_SrcR->h;

    DestR.x = m_x_center - explosion_size / 2;
    DestR.y = m_y_center - explosion_size / 2;
    DestR.w = explosion_size;
    DestR.h = explosion_size;

    SDL_RenderCopy(renderer, m_texture, &SrcR, &DestR);
}

