#ifndef EXITDISPLAY_H
#define EXITDISPLAY_H

#include "Display/Display.h"

class ExitDisplay : public Display
{
    public:
        ExitDisplay(bool* running = nullptr);
        ~ExitDisplay();
        ExitDisplay(const ExitDisplay& other) = delete; /**< \brief Default copy constructor is disabled */
        ExitDisplay& operator=(const ExitDisplay&) = delete; /**< \brief Default operator = is disabled */

        void Enter(int mode = 0);

        void Update();
        void Draw(SDL_Renderer* renderer) const;

    protected:

    private:
        bool*   m_running;
};

#endif // EXITDISPLAY_H
