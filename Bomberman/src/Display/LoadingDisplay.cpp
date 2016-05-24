#include "Display\LoadingDisplay.h"
#include "System\TextRenderer.h"
#include "Display/GameDisplay.h"
#include <string>
#include <sstream>

LoadingDisplay::LoadingDisplay(SDL_Texture* texture,
                               SDL_Renderer* renderer,
                               unsigned int window_width,
                               unsigned int window_height,
                               unsigned int max_level)
    : Display(),
      m_texture(texture),
      m_renderer(renderer),
      m_window_width(window_width),
      m_window_height(window_height),
      m_current_level(1),
      m_max_level(max_level)
{
    MakeTexture();
}

LoadingDisplay::~LoadingDisplay()
{
    for (auto i = m_textures.begin(); i != m_textures.end(); ++i)
    {
        SDL_DestroyTexture(*i);
    }
    m_textures.clear();
    m_textures_draw_src.clear();
    m_textures_draw_dest.clear();
}

void LoadingDisplay::Enter(int mode)
{
    if (mode == 0)
    {
        m_leave_previous = true;
        m_leave_next = false;
        m_timer.Pause();
        m_timer.ResetTimer();
    }
    else
    {
        m_timer.Unpause();
        m_timer.ResetTimer();
        m_current_level = mode;
        m_leave_next = false;
        m_leave_previous = false;
        MakeTexture();
    }
}

int LoadingDisplay::Destroy()
{
    for (auto i = m_textures.begin(); i != m_textures.end(); ++i)
    {
        SDL_DestroyTexture(*i);
    }
    m_textures.clear();
    m_textures_draw_src.clear();
    m_textures_draw_dest.clear();
    return 0;
}

void LoadingDisplay::Update()
{
    if (m_timer.GetTimeElapsed() > 1000 && !m_leave_next)
    {
        m_leave_next = true;
        m_next_display = new GameDisplay(m_texture,m_current_level);
    }
}

void LoadingDisplay::Draw(SDL_Renderer* renderer) const
{
    for (unsigned int i=0; i<m_textures.size(); ++i)
    {
        SDL_RenderCopy(renderer,m_textures[i],&m_textures_draw_src[i],&m_textures_draw_dest[i]);
    }
}

void LoadingDisplay::MakeTexture()
{
    Destroy();
    m_timer.ResetTimer();
    #ifdef _WIN32
    TextRenderer text_renderer("resources\\Zabdilus.ttf",96);
    #else //LINUX
    TextRenderer text_renderer("resources/Zabdilus.ttf",96);
    #endif
    SDL_Color color = {255, 242, 0, 255};
    SDL_Rect SrcR = { 0, 0, 0, 0 };
    SDL_Rect DestR = { 0, 0, 0, 0 };
    SDL_Texture* image;

    std::stringstream sstm;
    sstm << "STAGE " << m_current_level;
    std::string curr_lvl = sstm.str();

    image = text_renderer.RenderText(curr_lvl, color, m_renderer);
    SDL_QueryTexture(image, NULL, NULL, &(SrcR.w), &(SrcR.h));
    DestR.x = m_window_width / 2 -  SrcR.w / 2;
    DestR.y = m_window_height / 2 - SrcR.h / 2;
    DestR.h = SrcR.h;
    DestR.w = SrcR.w;
    m_textures.push_back(image);
    m_textures_draw_src.push_back(SrcR);
    m_textures_draw_dest.push_back(DestR);
}
