#ifndef EXPLOSION_H
#define EXPLOSION_H

// in Explosion.h Explosion.cpp ExplosionManager.h ExplosionManager.cpp
//#define DEBUG_OUTPUT

#ifdef DEBUG_OUTPUT
#include<iostream>
#endif // DEBUG_OUTPUT

#include <SDL.h>
#include "Timer.h"

class Explosion
{
    public:
        Explosion(unsigned int duration,
                  unsigned int x_center,
                  unsigned int y_center,
                  double intensity,
                  unsigned int tile_size,
                  SDL_Texture* texture,
                  SDL_Rect*  start_SrcR);

        void Update();
        bool IsExploding() const;
        void Draw(SDL_Renderer* renderer) const;

    protected:

    private:
        Timer           m_timer;
        unsigned int    m_duration;
        bool            m_exploding;
        unsigned int    m_x_center;
        unsigned int    m_y_center;
        double          m_intensity;
        unsigned int    m_tile_size;
        SDL_Texture*    m_texture;
        SDL_Rect*       m_start_SrcR;
        unsigned int    m_phase_number;

        static const unsigned int NUMBER_OF_PHASES = 74;
        // defined by number of different textures for explosion in textures.bmp

};

#endif // EXPLOSION_H
