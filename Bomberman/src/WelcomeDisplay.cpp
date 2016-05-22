#include "WelcomeDisplay.h"
#include "GameDisplay.h"
#include <SDL.h>
#include "TextRenderer.h"

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
    TextRenderer text_renderer("resources\\Zabdilus.ttf",64);

    SDL_Rect SrcR;
    SrcR.x = 0;
    SrcR.y = 0;
    SDL_Rect DestR;
    DestR.x = 200;
    DestR.y = 200;
    SDL_Color color = { 0, 255, 255, 255 };
	SDL_Texture *image;

	image = text_renderer.RenderText("Welcome to Bomberman!", color, renderer);
	if (image == nullptr){
		return;
	}
	SDL_QueryTexture(image, NULL, NULL, &(SrcR.w), &(SrcR.h));
    DestR.h = SrcR.h;
    DestR.w = SrcR.w;
    SDL_RenderCopy(renderer,image,&SrcR,&DestR);
    SDL_DestroyTexture(image);

    image = text_renderer.RenderText("Press ENTER to start.", color, renderer);
    if (image == nullptr){
        return;
    }
    SDL_QueryTexture(image, NULL, NULL, &(SrcR.w), &(SrcR.h));
    DestR.h = SrcR.h;
    DestR.w = SrcR.w;
    DestR.y += SrcR.h;
    SDL_RenderCopy(renderer,image,&SrcR,&DestR);
    SDL_DestroyTexture(image);

}
