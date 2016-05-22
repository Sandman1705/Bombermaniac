#ifndef WELCOMEDISPLAY_H
#define WELCOMEDISPLAY_H

#include "Display.h"
#include "SDL.h"

class WelcomeDisplay : public Display
{
    public:
        WelcomeDisplay(SDL_Texture* texture, SDL_Renderer* renderer, KeyboardInput* keyboard_input = nullptr);
        virtual ~WelcomeDisplay();

        void Enter();

        void Update();
        void Draw(SDL_Renderer* renderer) const;

    protected:

    private:
        SDL_Texture*    m_texture;
        SDL_Renderer*   m_renderer;

        bool            m_pressed_next;
        bool            m_pressed_previous;
};

#endif // WELCOMEDISPLAY_H
