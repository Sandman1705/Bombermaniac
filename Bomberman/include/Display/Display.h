#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL.h>
#include <string>
#include "System/KeyboardInput.h"

class Display
{
    public:
        Display(KeyboardInput* keyboard_input = nullptr);
        virtual ~Display() = 0;

        virtual void Init();
        virtual void Enter();
        virtual void Leave();
        virtual void Destroy();

        virtual void Update() = 0;
        virtual void Draw(SDL_Renderer* renderer) const = 0;

        bool ShouldLeaveToPrevious() { return m_leave_previous; }
        bool ShouldLeaveToNext() { return m_leave_next; }
        Display* NextDisplay() { return m_next_display; }

    protected:
        bool            m_leave_previous;
        bool            m_leave_next;
        Display*        m_next_display;
        KeyboardInput*  m_keyboard_input;

    private:

};

#endif // DISPLAY_H
