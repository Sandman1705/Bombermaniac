#include "DisplayManager.h"

DisplayManager::DisplayManager()
{
    //ctor
}

DisplayManager::~DisplayManager()
{
    //dtor
}

void DisplayManager::AddDisplay(Display* display)
{
    m_displays.top()->Leave();
    m_displays.push(display);
}

void DisplayManager::PopDisplay()
{
    m_displays.pop();
    m_displays.top()->Enter();
}

Display* DisplayManager::TopDisplay()
{
    return m_displays.top();
}
