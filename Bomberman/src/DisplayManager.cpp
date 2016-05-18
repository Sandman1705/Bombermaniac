#include "DisplayManager.h"

DisplayManager::DisplayManager()
{
    //ctor
}

DisplayManager::~DisplayManager()
{
    //dtor
}

void DisplayManager::EnterDisplay(Display* display)
{
    m_displays.top()->Leave();
    m_displays.push(display);
}

void DisplayManager::ExitDisplay()
{
    m_displays.pop();
    m_displays.top()->Enter();
}

Display* DisplayManager::CurrentDisplay()
{
    return m_displays.top();
}
