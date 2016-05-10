#ifndef BOMB_H
#define BOMB_H

// in Bomb.h Bomb.cpp BombManager.h BombManager.cpp
//#define DEBUG_OUTPUT

#include<SDL.h>
#include"Timer.h"

class Bomb
{
    public:
        Bomb(unsigned int fuse_duration,
             SDL_Texture* texture,
             SDL_Rect* SrcR,
             unsigned int x,
             unsigned int y,
             unsigned int bomb_size,
             double intensity = 1.0);
        #ifdef DEBUG_OUTPUT
        ~Bomb();
        #endif // DEBUG_OUTPUT

        unsigned int Get_x () { return m_x; }
        unsigned int Get_y () { return m_y; }
        unsigned int Get_bomb_size () { return m_draw_size; }
        double Get_intensity () { return m_intensity; }

        void BurnFuse();
        bool Explode();
        void Draw(SDL_Renderer* renderer);

    protected:

    private:
        Timer           m_timer;
        unsigned int    m_fuse_duration;
        SDL_Texture*    m_texture;
        SDL_Rect*       m_SrcR;
        bool            m_explode;
        unsigned int    m_x;
        unsigned int    m_y;
        unsigned int    m_draw_size;
        double          m_intensity;
};

#endif // BOMB_H
