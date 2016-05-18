#include "WelcomeDisplay.h"

WelcomeDisplay::WelcomeDisplay(SDL_Texture* texture, KeyboardInput* keyboard_input)
    : Display(keyboard_input), m_texture(texture)
{
}

WelcomeDisplay::~WelcomeDisplay()
{
}

void WelcomeDisplay::Update()
{
}

void WelcomeDisplay::Draw(SDL_Renderer* renderer) const
{
    SDL_Rect SrcR; // {66,302,568,98};
    SrcR.h = 66;
    SrcR.w = 302;
    SrcR.x = 568;
    SrcR.y = 98;
    SDL_Rect DestR; //{66,302,0,0};
    DestR.h = 66;
    DestR.w = 302;
    DestR.x = 0;
    DestR.y = 0;

    SDL_RenderCopy(renderer,m_texture,&SrcR,&DestR);
}
