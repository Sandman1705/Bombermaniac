#include "Display\LoadingDisplay.h"
#include "System\TextRenderer.h"
#include "Display/GameDisplay.h"
#include "Constants/ResourcesConstants.h"
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
      m_max_level(max_level),
      m_game_over(false)
{
    std::stringstream sstm;
    sstm << "STAGE " << m_current_level;
    MakeTexture(sstm.str());
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
        m_leave_previous = false;
        m_leave_next = false;
        m_timer.Unpause();
        m_timer.ResetTimer();
        m_game_over = true;
        MakeTexture("GAME OVER");
    }
    else
    {
        m_timer.Unpause();
        m_timer.ResetTimer();
        m_current_level = mode;
        m_leave_next = false;
        m_leave_previous = false;
        if (m_current_level <= RESOURCES_LEVEL_COUNT)
        {
            std::stringstream sstm;
            sstm << "STAGE " << m_current_level;
            MakeTexture(sstm.str());
        }
        else // GAME COMPLETED / ALL LEVEL FINISHED
        {
            MakeTexture("GAME COMPLETED");
            m_game_over = true;
        }
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
    if (m_timer.GetTimeElapsed() > 1000)
    {
        if (m_game_over)
        {
            m_leave_previous = true;
        }
        else // (!m_leave_next)
        {
            m_leave_next = true;
            m_next_display = new GameDisplay(m_texture,m_renderer,m_window_width,m_window_height,m_current_level);
        }
    }
}

void LoadingDisplay::Draw(SDL_Renderer* renderer) const
{
    for (unsigned int i=0; i<m_textures.size(); ++i)
    {
        SDL_RenderCopy(renderer,m_textures[i],&m_textures_draw_src[i],&m_textures_draw_dest[i]);
    }
}

void LoadingDisplay::MakeTexture(std::string text)
{
    Destroy();
    m_timer.ResetTimer();

    std::string path_font = RESOURCES_BASE_PATH + RESOURCES_FONT;
    TextRenderer text_renderer(path_font,96);

    SDL_Color color = {0, 0, 200, 255};
    SDL_Rect SrcR = { 0, 0, 0, 0 };
    SDL_Rect DestR = { 0, 0, 0, 0 };
    SDL_Texture* image;

    image = text_renderer.RenderText(text, color, m_renderer);
    SDL_QueryTexture(image, NULL, NULL, &(SrcR.w), &(SrcR.h));
    DestR.x = m_window_width / 2 -  SrcR.w / 2;
    DestR.y = m_window_height / 2 - SrcR.h / 2;
    DestR.h = SrcR.h;
    DestR.w = SrcR.w;
    m_textures.push_back(image);
    m_textures_draw_src.push_back(SrcR);
    m_textures_draw_dest.push_back(DestR);
}
