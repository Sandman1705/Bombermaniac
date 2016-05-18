#include "GameDisplay.h"
#include "ScreenTimer.h"

GameDisplay::GameDisplay(unsigned int number_of_screen_elements)
{
    m_display_elements.reserve(number_of_screen_elements);
}

GameDisplay::~GameDisplay()
{
    for (auto i = m_display_elements.begin(); i != m_display_elements.end(); ++i)
    {
        delete (*i);
    }
}

void GameDisplay::AddDisplayElement(DisplayElement* display_element)
{
    m_display_elements.push_back(display_element);
}

void GameDisplay::Enter()
{
    ScreenTimer::Instance()->Unpause();
}

void GameDisplay::Leave()
{
    ScreenTimer::Instance()->Pause();
}

void GameDisplay::Update()
{
    for (auto i = m_display_elements.begin(); i != m_display_elements.end(); ++i)
    {
        (*i)->Update();
    }
}

void GameDisplay::Draw(SDL_Renderer* renderer) const
{
    for (auto i = m_display_elements.cbegin(); i != m_display_elements.cend(); ++i)
    {
        (*i)->Draw(renderer);
    }
}
