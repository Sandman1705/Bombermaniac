#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL.h>
#include <string>

class Display
{
    public:
        Display();
        virtual ~Display() = 0;

        virtual void Enter();
        virtual void Leave();

        virtual void Update() = 0;
        virtual void Draw(SDL_Renderer* renderer) = 0;

    protected:

    private:

};

#endif // DISPLAY_H
