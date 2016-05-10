#include "Timer.h"
#include <SDL.h>

Timer::Timer()
{
    pastTicks = SDL_GetTicks();
}

void Timer::resetTimer()
{
    pastTicks = SDL_GetTicks();
}

unsigned int Timer::getTimeElapsed()
{
    return SDL_GetTicks() - pastTicks;
}
