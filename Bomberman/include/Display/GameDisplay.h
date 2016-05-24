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
                    unsigned int number_of_screen_elements = 5);
        ~GameDisplay();

        void AddDisplayElement(DisplayElement* display_element);

        void Init();
        void Enter();
        void Leave();
        void Destroy();

        void Update();
        void Draw(SDL_Renderer* renderer) const;

    protected:

    private:
        std::vector<DisplayElement*>    m_display_elements;
        Relay*                          m_relay;
        SDL_Texture*                    m_texture;
};

#endif // GAMEDISPLAY_H
