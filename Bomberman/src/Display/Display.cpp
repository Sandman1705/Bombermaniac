#include "Display/Display.h"

Display::Display()
    : m_leave_previous(false),
      m_leave_next(false),
      m_next_display(nullptr),
      m_keyboard_input(KeyboardInput::Instance())
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
    m_leave_previous = false;
    m_leave_next = false;
}

void Display::Leave()
{
}

void Display::Destroy()
{
}
