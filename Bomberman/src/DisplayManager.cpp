#include "DisplayManager.h"

#include "ExitDisplay.h"
#include "WelcomeDisplay.h"
#include "MainMenuDisplay.h"

DisplayManager::DisplayManager(SDL_Texture* texture, SDL_Renderer* renderer, KeyboardInput* keyboard_input, bool* running)
    : m_renderer(renderer)
{
    m_displays.push(new ExitDisplay(running));
    m_displays.push(new WelcomeDisplay(texture,renderer,keyboard_input));
    //m_displays.push(new MainMenuDisplay(texture,renderer,keyboard_input));
}

DisplayManager::~DisplayManager()
{
}

void DisplayManager::EnterDisplay(Display* display)
{
    m_displays.top()->Leave();
    m_displays.push(display);
    m_displays.top()->Init();
}

void DisplayManager::LeaveDisplay()
{
    m_displays.top()->Destroy();
    m_displays.pop();
    m_displays.top()->Enter();
}

Display* DisplayManager::CurrentDisplay()
{
    return m_displays.top();
}

void DisplayManager::Update()
{
    if (CurrentDisplay()->ShouldLeaveToNext())
        EnterDisplay(CurrentDisplay()->NextDisplay());
    else if (CurrentDisplay()->ShouldLeaveToPrevious())
    {
        LeaveDisplay();
        Update();
    }
    else
        CurrentDisplay()->Update();
}

void DisplayManager::Draw(SDL_Renderer* renderer)
{
    CurrentDisplay()->Draw(renderer);
}
