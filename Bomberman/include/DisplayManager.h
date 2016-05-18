#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include "Display.h"
#include <stack>

class DisplayManager
{
    public:
        DisplayManager();
        ~DisplayManager();

        void AddDisplay(Display* display);
        void PopDisplay();
        Display* TopDisplay();

    protected:

    private:
        std::stack<Display*> m_displays;
};

#endif // DISPLAYMANAGER_H
