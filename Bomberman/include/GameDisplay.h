#ifndef GAMEDISPLAY_H
#define GAMEDISPLAY_H

#include "Display.h"
#include "DisplayElement.h"
#include <vector>

class GameDisplay : public Display
{
    public:
        GameDisplay(unsigned int number_of_screen_elements = 1);
        ~GameDisplay();

        void AddDisplayElement(DisplayElement* display_element);

        void Enter();
        void Leave();

        void Update();
        void Draw(SDL_Renderer* renderer) const;

    protected:

    private:
        std::vector<DisplayElement*>    m_display_elements;
};

#endif // GAMEDISPLAY_H
