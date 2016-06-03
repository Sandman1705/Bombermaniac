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
            LIFE,
            SPEED_DECREASE,
            BOMB_DECREASE,
            DAMAGE_DECREASE
        };
        PickUp(SDL_Texture* texture,
               PickUpType type,
               int value,
               unsigned int x,
               unsigned int y,
               unsigned int draw_size = 30);

        PickUpType GetType() const { return m_type; }
        int GetValue() const { return m_value; }

        bool IsUsed();
        void Use();

        void Draw(SDL_Renderer* renderer) const;

        unsigned int GetX() const { return m_x; }
        unsigned int GetY() const { return m_y; }
        unsigned int GetSize() const { return m_draw_size; }

    protected:

    private:
        SDL_Texture*    m_texture;
        PickUpType      m_type;
        int             m_value;
        unsigned int    m_x;
        unsigned int    m_y;
        unsigned int    m_draw_size;
        bool            m_used;

};

#endif // PICKUP_H
