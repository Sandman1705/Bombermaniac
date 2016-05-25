#ifndef PICKUP_H
#define PICKUP_H

#include <SDL.h>

class PickUp
{
    public:
        enum PickUpType
        {
            EXIT,
            SPEED,
            BOMB,
            DAMAGE,
            LIFE
        };
        PickUp(SDL_Texture* texture,
               PickUpType type,
               int value,
               unsigned int x,
               unsigned int y,
               unsigned int draw_size = 30);

        PickUpType GetType() const { return m_type; }
        int GetValue() const { return m_value; }

        void Draw(SDL_Renderer* renderer) const;

    protected:

    private:
        SDL_Texture*    m_texture;
        PickUpType      m_type;
        int             m_value;
        unsigned int    m_x;
        unsigned int    m_y;
        unsigned int    m_draw_size;

};

#endif // PICKUP_H
