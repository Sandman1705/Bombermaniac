#include "Timer.h"
#include <SDL.h>

Timer::Timer()
{
    m_pastTicks = SDL_GetTicks();
}

void Timer::ResetTimer()
{
    m_pastTicks = SDL_GetTicks();
}

void Timer::DecreaseTimer(unsigned long interval)
{
    m_pastTicks += interval;
}

unsigned long Timer::GetTimeElapsed()
{
    return SDL_GetTicks() - m_pastTicks;
}
