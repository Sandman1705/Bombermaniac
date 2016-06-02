#ifndef GAMEDISPLAY_H
#define GAMEDISPLAY_H

#include "Display/Display.h"
#include "Display/DisplayElement.h"
#include "Utility/Relay.h"
#include <vector>

class GameDisplay : public Display
{
    public:
        GameDisplay(SDL_Texture* texture,
                    SDL_Renderer* renderer,
                    unsigned int window_width,
                    unsigned int window_height,
                    unsigned int current_level,
                    unsigned int number_of_screen_elements = 6);
        ~GameDisplay();

        void AddDisplayElement(DisplayElement* display_element);

        void Init();
        void Enter(int mode = 0);
        void Leave();
        int Destroy();

        void Update();
        void Draw(SDL_Renderer* renderer) const;

    protected:

    private:
        std::vector<DisplayElement*>    m_display_elements;
        Relay*                          m_relay;
        SDL_Texture*                    m_texture;
        SDL_Renderer*                   m_renderer;
        unsigned int                    m_window_width;
        unsigned int                    m_window_height;
        unsigned int                    m_current_level;
        bool                            m_level_completed;
        bool                            m_play_music = true;
        Mix_Music*                      m_music = NULL;
};

#endif // GAMEDISPLAY_H
