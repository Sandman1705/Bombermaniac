#ifndef WELCOMEDISPLAY_H
#define WELCOMEDISPLAY_H

#include "Display/Display.h"
#include "SDL.h"
#include <vector>

class WelcomeDisplay : public Display
{
    public:
        WelcomeDisplay(SDL_Texture* texture,
                       SDL_Renderer* renderer,
                       unsigned int m_window_width,
                       unsigned int m_window_height);
        ~WelcomeDisplay();
        WelcomeDisplay(const WelcomeDisplay& other) = delete; /**< \brief Default copy constructor is disabled */
        WelcomeDisplay& operator=(const WelcomeDisplay&) = delete; /**< \brief Default operator = is disabled */

        void Enter(int mode = 0);

        void Update();
        void Draw(SDL_Renderer* renderer) const;

    protected:

    private:
        SDL_Texture*                m_texture;
        SDL_Renderer*               m_renderer;
        std::vector<SDL_Texture*>   m_textures;
        std::vector<SDL_Rect>       m_textures_draw_src;
        std::vector<SDL_Rect>       m_textures_draw_dest;

        bool                        m_pressed_next;
        bool                        m_pressed_previous;
        unsigned int                m_window_width;
        unsigned int                m_window_height;
};

#endif // WELCOMEDISPLAY_H
