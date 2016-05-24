#include "Display/MainMenuDisplay.h"
#include "System/TextRenderer.h"
#include "Display/GameDisplay.h"
#include "Display/LoadingDisplay.h"

//#define DEBUG_OUTPUT_MAIN_MENU_DISPAY

#ifdef DEBUG_OUTPUT_MAIN_MENU_DISPAY
#include <iostream>
#endif // DEBUG_OUTPUT_MAIN_MENU_DISPAY

MainMenuDisplay::MainMenuDisplay(SDL_Texture* texture,
                                 SDL_Renderer* renderer,
                                 unsigned int window_width,
                                 unsigned int window_height)
    : Display(),
      m_texture(texture),
      m_renderer(renderer),
      m_arrow(0),
      m_button_pressed_down(false),
      m_button_pressed_up(false),
      m_button_pressed_enter(false),
      m_window_width(window_width),
      m_window_height(window_height)
{
    #ifdef _WIN32
    TextRenderer text_renderer("resources\\Zabdilus.ttf",64);
    #else //LINUX
    TextRenderer text_renderer("resources/Zabdilus.ttf",64);
    #endif
    SDL_Color color = {255, 0, 0, 255};
    SDL_Rect SrcR = { 0, 0, 0, 0 };
    SDL_Rect DestR = { 0, 0, 0, 0 };
    SDL_Texture* image;

    image = text_renderer.RenderText("NEW GAME", color, renderer);
    SDL_QueryTexture(image, NULL, NULL, &(SrcR.w), &(SrcR.h));
    DestR.x = window_width / 2 -  SrcR.w / 2;
    DestR.y = window_height / 2 - SrcR.h / 2 - SrcR.h;
    DestR.h = SrcR.h;
    DestR.w = SrcR.w;
    m_options_textures.push_back(image);
    m_options_draw_src.push_back(SrcR);
    m_options_draw_dest.push_back(DestR);

    image = text_renderer.RenderText("OPTIONS", color, renderer);
    SDL_QueryTexture(image, NULL, NULL, &(SrcR.w), &(SrcR.h));
    DestR.y += SrcR.h;
    DestR.h = SrcR.h;
    DestR.w = SrcR.w;
    m_options_textures.push_back(image);
    m_options_draw_src.push_back(SrcR);
    m_options_draw_dest.push_back(DestR);

    image = text_renderer.RenderText("EXIT", color, renderer);
    SDL_QueryTexture(image, NULL, NULL, &(SrcR.w), &(SrcR.h));
    DestR.y += SrcR.h;
    DestR.h = SrcR.h;
    DestR.w = SrcR.w;
    m_options_textures.push_back(image);
    m_options_draw_src.push_back(SrcR);
    m_options_draw_dest.push_back(DestR);

    m_arrow_texture = text_renderer.RenderText(">", color, renderer);
    SDL_QueryTexture(m_arrow_texture, NULL, NULL, &m_arrow_width, &m_arrow_height);

}

MainMenuDisplay::~MainMenuDisplay()
{
    for (auto i = m_options_textures.begin(); i != m_options_textures.end(); ++i)
    {
        SDL_DestroyTexture(*i);
    }
    SDL_DestroyTexture(m_arrow_texture);
    m_options_textures.clear();
    m_options_draw_dest.clear();
    m_options_draw_src.clear();
}

void MainMenuDisplay::Init()
{
    Enter();
}

void MainMenuDisplay::Enter(int mode)
{
    m_leave_next = false;
    m_leave_previous = false;
    m_arrow = 0;
    m_button_pressed_down = false;
    m_button_pressed_up = false;
    m_button_pressed_enter = false;
}

void MainMenuDisplay::Leave()
{
}

int MainMenuDisplay::Destroy()
{
    for (auto i = m_options_textures.begin(); i != m_options_textures.end(); ++i)
    {
        SDL_DestroyTexture(*i);
    }
    SDL_DestroyTexture(m_arrow_texture);
    m_options_textures.clear();
    m_options_draw_dest.clear();
    m_options_draw_src.clear();
    return 0;
}

void MainMenuDisplay::Update()
{
    if (m_button_pressed_down && m_keyboard_input->IsKeyOn(SDLK_DOWN))
    {
        m_button_pressed_down = false;
        ++m_arrow;
        if (m_arrow >= (int)m_options_textures.size())
            m_arrow = 0;
    }
    if (m_button_pressed_up && m_keyboard_input->IsKeyOn(SDLK_UP))
    {
        m_button_pressed_up = false;
        --m_arrow;
        if (m_arrow < 0)
            m_arrow = m_options_textures.size() - 1;
    }
    if (m_button_pressed_enter && m_keyboard_input->IsKeyOn(SDLK_RETURN))
    {
        switch(m_arrow)
        {
        case 0:
            m_next_display = new LoadingDisplay(m_texture,m_renderer,m_window_width,m_window_height,10);//GameDisplay(m_texture,1);
            m_leave_next = true;
            break;
        case 1:
            break;
        case 2:
            m_leave_previous = true;
            break;
        default:
            break;
        }
    }

    if ( !(m_keyboard_input->IsKeyOn(SDLK_DOWN)) )
        m_button_pressed_down = true;
    if ( !(m_keyboard_input->IsKeyOn(SDLK_UP)) )
        m_button_pressed_up = true;
    if ( !(m_keyboard_input->IsKeyOn(SDLK_RETURN)) )
        m_button_pressed_enter = true;
}

void MainMenuDisplay::Draw(SDL_Renderer* renderer) const
{
    #ifdef DEBUG_OUTPUT_MAIN_MENU_DISPAY
    std::cout << "MainMenuDisplay arror: " << m_arrow << std::endl;
    #endif // DEBUG_OUTPUT_MAIN_MENU_DISPAY
    for (unsigned int i=0; i<m_options_textures.size(); ++i)
    {
        SDL_RenderCopy(renderer,m_options_textures[i],&m_options_draw_src[i],&m_options_draw_dest[i]);
    }
    SDL_Rect SrcR;
    SrcR.h = m_arrow_height;
    SrcR.w = m_arrow_width;
    SrcR.x = 0;
    SrcR.y = 0;
    SDL_Rect DestR;
    DestR.h = m_arrow_height;
    DestR.w = m_arrow_width;
    DestR.x = m_options_draw_dest[m_arrow].x-m_arrow_width-50;
    DestR.y = m_options_draw_dest[m_arrow].y;
    SDL_RenderCopy(renderer,m_arrow_texture,&SrcR,&DestR);
}

