#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include "Display/Display.h"
#include "SDL.h"
#include <stack>

class DisplayManager
{
    public:
        DisplayManager(SDL_Texture* texture,
                       SDL_Renderer* renderer,
                       bool* running,
                       unsigned int window_width,
                       unsigned int window_height);
        ~DisplayManager();
        DisplayManager(const DisplayManager& other) = delete; /**< \brief Default copy constructor is disabled */
        DisplayManager& operator=(const DisplayManager&) = delete; /**< \brief Default operator = is disabled */

        void EnterDisplay(Display* display);
        void LeaveDisplay();
        Display* CurrentDisplay();

        void Update();
        void Draw(SDL_Renderer* renderer);

    protected:

    private:
        std::stack<Display*> m_displays;
        SDL_Renderer*        m_renderer;

        unsigned int         m_window_width;
        unsigned int         m_window_height;
};

#endif // DISPLAYMANAGER_H
