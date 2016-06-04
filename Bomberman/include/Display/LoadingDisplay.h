#ifndef LOADINGDISPLAY_H
#define LOADINGDISPLAY_H

#include "Display/Display.h"
#include "Utility/Timer.h"
#include <SDL.h>
#include <vector>

class LoadingDisplay : public Display
{
    public:
        LoadingDisplay(SDL_Texture* texture,
                       SDL_Renderer* renderer,
                       unsigned int window_width,
                       unsigned int window_height,
                       unsigned int max_level);
        virtual ~LoadingDisplay();

        void Init();
        void Enter(int mode);
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
        unsigned int                m_window_width;
        unsigned int                m_window_height;
        unsigned int                m_current_level;
        const unsigned int          m_max_level;
        Timer                       m_timer;
        bool                        m_game_over;
        Mix_Music*                  m_music;

        void MakeTexture(std::string text);
        void DestroyTextures();

};

#endif // LOADINGDISPLAY_H
