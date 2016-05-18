#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include "Display.h"
#include <stack>

class DisplayManager
{
    public:
        DisplayManager();
        ~DisplayManager();

        void EnterDisplay(Display* display);
        void ExitDisplay();
        Display* CurrentDisplay();

    protected:

    private:
        std::stack<Display*> m_displays;
};

#endif // DISPLAYMANAGER_H
