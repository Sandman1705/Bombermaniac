#ifndef EXITDISPLAY_H
#define EXITDISPLAY_H

#include "Display/Display.h"

class ExitDisplay : public Display
{
    public:
        ExitDisplay(bool* running = nullptr);
        ~ExitDisplay();

        void Enter();

        void Update();
        void Draw(SDL_Renderer* renderer) const;

    protected:

    private:
        bool*   m_running;
};

#endif // EXITDISPLAY_H
