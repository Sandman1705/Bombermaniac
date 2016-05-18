#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL.h>
#include <string>
#include "KeyboardInput.h"

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

        bool ShouldEnter() { return m_enter; }
        bool ShouldLeave() { return m_leave; }
        Display* NextDisplay() { return m_next_display; }

    protected:
        bool            m_enter;
        bool            m_leave;
        Display*        m_next_display;
        KeyboardInput*  m_keyboard_input;

    private:

};

#endif // DISPLAY_H
