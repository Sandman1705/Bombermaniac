#include "Timer.h"
#include <SDL.h>

Timer::Timer()
    : m_screen_timer(ScreenTimer::Instance()),
      m_past_ticks(m_screen_timer->GetTimeElapsed()),
      m_paused_ticks(m_past_ticks),
      m_paused(false)
{
}

Timer::Timer(ScreenTimer* screen_timer)
    : m_screen_timer(screen_timer),
      m_past_ticks(m_screen_timer->GetTimeElapsed()),
      m_paused_ticks(m_past_ticks),
      m_paused(false)
{
}

void Timer::ResetTimer()
{
    m_past_ticks = m_screen_timer->GetTimeElapsed();
}

void Timer::DecreaseTimer(unsigned long interval)
{
    m_past_ticks += interval;
}

unsigned long Timer::GetTimeElapsed() const
{
    if (m_paused)
        return m_paused_ticks - m_past_ticks;
    else
        return m_screen_timer->GetTimeElapsed() - m_past_ticks;
}

void Timer::Pause()
{
    if (!m_paused)
    {
        m_paused_ticks = m_screen_timer->GetTimeElapsed();
        m_paused = true;
    }
}

void Timer::Unpause()
{
    if (m_paused)
    {
        m_past_ticks = m_screen_timer->GetTimeElapsed() - (m_paused_ticks - m_past_ticks);
        m_paused = false;
    }
}

bool Timer::IsPaused() const
{
    return m_paused;
}
