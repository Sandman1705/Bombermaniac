#ifndef BOMB_H
#define BOMB_H

#include<SDL.h>
#include"Timer.h"

class Bomb
{
    public:
        Bomb(unsigned int fuse_duration,
             SDL_Texture* texture,
             unsigned int x,
             unsigned int y,
             unsigned int bomb_size);
        //virtual ~Bomb();

        void UpdateFuse();
        bool Explode();
        void Draw(SDL_Renderer* renderer);

        void DEBUG_ShowTimer();

    protected:

    private:
        Timer           m_timer;
        unsigned int    m_fuse_duration;
        SDL_Texture*    m_texture;
        bool            m_explode;
        unsigned int    m_x;
        unsigned int    m_y;
        unsigned int    m_draw_size;
};

#endif // BOMB_H
