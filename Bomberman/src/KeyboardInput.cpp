#include "KeyboardInput.h"

//#define DEBUG_OUTPUT

#ifdef DEBUG_OUTPUT
#include<iostream>
#endif // DEBUG_OUTPUT

KeyboardInput::KeyboardInput()
{
}

void KeyboardInput::TurnKeyOn(SDL_Keycode key)
{
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

