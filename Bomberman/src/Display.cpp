#include "Display.h"

Display::Display(KeyboardInput* keyboard_input)
    : m_enter(false),
      m_leave(false),
      m_next_display(nullptr),
      m_keyboard_input(keyboard_input)
{
}

Display::~Display()
{
}

void Display::Init()
{
}

void Display::Enter()
{
}

void Display::Leave()
{
}

void Display::Destroy()
{
}
