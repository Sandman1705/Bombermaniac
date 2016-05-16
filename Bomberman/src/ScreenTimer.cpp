#include "ScreenTimer.h"
#include <SDL.h>

ScreenTimer* ScreenTimer::s_instance;

ScreenTimer::ScreenTimer()
    : m_past_ticks(SDL_GetTicks()),
      m_paused_ticks(m_past_ticks),
      m_paused(false)
{
}

ScreenTimer* ScreenTimer::Instance()
{
    if (s_instance == 0) {
        s_instance = new ScreenTimer();
    }
    return s_instance;
}

void ScreenTimer::ResetTimer()
{
    m_past_ticks = SDL_GetTicks();
}

void ScreenTimer::DecreaseTimer(unsigned long interval)
{
    m_past_ticks += interval;
}

unsigned long ScreenTimer::GetTimeElapsed() const
{
    if (m_paused)
        return m_paused_ticks - m_past_ticks;
    else
        return SDL_GetTicks() - m_past_ticks;
}

void ScreenTimer::Pause()
{
    if (!m_paused)
    {
        m_paused_ticks = SDL_GetTicks();
        m_paused = true;
    }
}

void ScreenTimer::Unpause()
{
    if (m_paused)
    {
        m_past_ticks = SDL_GetTicks() - (m_paused_ticks - m_past_ticks);
        m_paused = false;
    }
}

bool ScreenTimer::IsPaused() const
{
    return m_paused;
}
