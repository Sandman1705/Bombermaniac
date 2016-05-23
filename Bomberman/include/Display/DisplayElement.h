#ifndef DISPLAYELEMENT_H
#define DISPLAYELEMENT_H

#include "SDL.h"
//#include "Utility/Relay.h"

class DisplayElement
{
    public:
        DisplayElement(SDL_Texture* texture);
        virtual ~DisplayElement() = 0;

        virtual void Update() = 0;
        virtual void Draw(SDL_Renderer* renderer) const = 0;

    protected:
        SDL_Texture*    m_texture;
        //Relay*          m_relay;

    private:
};

#endif // DISPLAYELEMENT_H
