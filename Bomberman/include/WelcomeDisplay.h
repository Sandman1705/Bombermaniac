#ifndef WELCOMEDISPLAY_H
#define WELCOMEDISPLAY_H

#include "Display.h"
#include "SDL.h"

class WelcomeDisplay : public Display
{
    public:
        WelcomeDisplay(SDL_Texture* texture, KeyboardInput* keyboard_input = nullptr);
        virtual ~WelcomeDisplay();

        void Update();
        void Draw(SDL_Renderer* renderer) const;

    protected:

    private:
        SDL_Texture*    m_texture;
};

#endif // WELCOMEDISPLAY_H
