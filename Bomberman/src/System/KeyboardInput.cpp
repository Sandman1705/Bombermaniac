#include "System/KeyboardInput.h"

//#define DEBUG_OUTPUT

#ifdef DEBUG_OUTPUT
#include<iostream>
#endif // DEBUG_OUTPUT

KeyboardInput::KeyboardInput()
{
}

void KeyboardInput::TurnKeyOn(SDL_Keycode key)
{
    if (key == SDLK_DOWN || key == SDLK_UP || key == SDLK_LEFT || key == SDLK_RIGHT)
    {
        m_keys_pressed[SDLK_DOWN]  = false;
        m_keys_pressed[SDLK_UP]    = false;
        m_keys_pressed[SDLK_LEFT]  = false;
        m_keys_pressed[SDLK_RIGHT] = false;
    }
    m_keys_pressed[key] = true;
    #ifdef DEBUG_OUTPUT
    std::cout << key << " is pressed" << std::endl;
    #endif // DEBUG_OUTPUT
}

void KeyboardInput::TurnKeyOff(SDL_Keycode key)
{
    m_keys_pressed[key] = false;
    #ifdef DEBUG_OUTPUT
    std::cout << key << " is released" << std::endl;
    #endif // DEBUG_OUTPUT
}

bool KeyboardInput::IsKeyOn(SDL_Keycode key)
{
    if (m_keys_pressed.count(key) > 0)
        return m_keys_pressed[key];
    else
        return false;
}

