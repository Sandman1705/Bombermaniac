#include "Timer.h"
#include <SDL.h>

Timer::Timer()
    : m_past_ticks(SDL_GetTicks()),
      m_paused_ticks(m_past_ticks),
      m_paused(false)
{
}

void Timer::ResetTimer()
{
    m_past_ticks = SDL_GetTicks();
}

void Timer::DecreaseTimer(unsigned long interval)
{
    m_past_ticks += interval;
}

unsigned long Timer::GetTimeElapsed()
{
    if (m_paused)
        return m_paused_ticks - m_past_ticks;
    else
        return SDL_GetTicks() - m_past_ticks;
}

void Timer::Pause()
{
    if (!m_paused)
    {
        m_paused_ticks = SDL_GetTicks();
        m_paused = true;
    }
}

void Timer::Unpause()
{
    if (m_paused)
    {
        m_past_ticks = SDL_GetTicks() - (m_paused_ticks - m_past_ticks);
        m_paused = false;
    }
}

bool Timer::IsPaused()
{
    return m_paused;
}
