#include "WelcomeDisplay.h"
#include "GameDisplay.h"

WelcomeDisplay::WelcomeDisplay(SDL_Texture* texture, KeyboardInput* keyboard_input)
    : Display(keyboard_input), m_texture(texture), m_pressed_next(false), m_pressed_previous(false)
{
}

WelcomeDisplay::~WelcomeDisplay()
{
}

void WelcomeDisplay::Enter()
{
    m_leave_previous = false;
    m_leave_next = false;
    m_pressed_next = false;
    m_pressed_previous = false;
}

void WelcomeDisplay::Update()
{
    if (m_pressed_next && m_keyboard_input->IsKeyOn(SDLK_RETURN))
    {
        m_pressed_next = false;
        m_next_display = new GameDisplay(m_texture,m_keyboard_input);
        m_leave_next = true;
    }
    if (m_pressed_previous && m_keyboard_input->IsKeyOn(SDLK_ESCAPE))
    {
        m_pressed_previous = false;
        m_leave_previous = true;
    }

    if ( !(m_keyboard_input->IsKeyOn(SDLK_RETURN)) )
        m_pressed_next = true;
    if ( !(m_keyboard_input->IsKeyOn(SDLK_ESCAPE)) )
        m_pressed_previous = true;
}

void WelcomeDisplay::Draw(SDL_Renderer* renderer) const
{
    SDL_Rect SrcR; // TODO Change welcome screen to something better
    SrcR.h = 66;
    SrcR.w = 302;
    SrcR.x = 568;
    SrcR.y = 98;
    SDL_Rect DestR;
    DestR.h = 66;
    DestR.w = 302;
    DestR.x = 0;
    DestR.y = 0;

    SDL_RenderCopy(renderer,m_texture,&SrcR,&DestR);
}
