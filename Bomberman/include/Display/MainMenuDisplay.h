#ifndef MAINMENUDISPLAY_H
#define MAINMENUDISPLAY_H

#include "Display/Display.h"
#include <vector>

class MainMenuDisplay : public Display
{
    public:
        MainMenuDisplay(SDL_Texture* texture,
                        SDL_Renderer* renderer,
                        unsigned int window_width,
                        unsigned int window_height);
        ~MainMenuDisplay();

        void Init();
        void Enter(int mode = 0);
        void Leave();
        int Destroy();

        void Update();
        void Draw(SDL_Renderer* renderer) const;

    protected:

    private:
        SDL_Texture*                m_texture;
        SDL_Renderer*               m_renderer;
        std::vector<SDL_Texture*>   m_textures;
        std::vector<SDL_Rect>       m_textures_draw_src;
        std::vector<SDL_Rect>       m_textures_draw_dest;
        SDL_Texture*                m_arrow_texture;
        int                         m_arrow_height;
        int                         m_arrow_width;
        int                         m_arrow;
        bool                        m_button_pressed_down;
        bool                        m_button_pressed_up;
        bool                        m_button_pressed_enter;
        unsigned int                m_window_width;
        unsigned int                m_window_height;

};

#endif // MAINMENUDISPLAY_H
