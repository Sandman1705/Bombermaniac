#ifndef BOMB_H
#define BOMB_H

// in Bomb.h Bomb.cpp BombManager.h BombManager.cpp
//#define DEBUG_OUTPUT

/**
 *  \file Bomb.h
 *
 *  Defines class Bomb which represents one bomb.
 *
 */

#include<SDL.h>
#include"Timer.h"

/** \class Bomb
 *  \brief Class which represents one bomb
 *  \details This class contains all properties of a bomb like it's coordinates
 *           on a map, it's size, time needed to explode as well as time
 *           currently elapsed since it was placed. Also contains a method
 *           Draw() which draws it on a proper place on the map.
 */
class Bomb
{
    public:
        /**
         *  \brief Constructor for Bomb
         *
         *  Makes an object of class Bomb according to given attributes
         *  \param fuse_duration the length of bomb's fuse.
         *  \param texture pointer to SDL_texture object from which the texture
         *         will be taken for method Draw()
         *  \param SrcR location and size of texture on given SLD_Texture
         *  \param x coordinate of the bomb on the map
         *  \param x coordinate of the bomb on the map
         *  \param bomb_size drawing size of the bomb according to 32 pixel tile
         *         size of the map
         *  \param intensity real value of bomb's blast radius (1.0 is radius of
         *         one tile size of the map
         *
         */
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

        unsigned int GetX() const { return m_x; }
        unsigned int GetY() const { return m_y; }
        unsigned int GetBombSize () const { return m_draw_size; }
        double GetIntensity () const { return m_intensity; }

        /**
         *  \brief Update function for class Bomb
         *
         *  Updates the values in class according to it's internal timer.
         *  Specifically, it checks if the bomb's fuse has run out and
         *  sets the appropriate value so that the call of method Explode()
         *  returns true;
         *
         *  \return void
         */
        void Update();
        /**
         *  \brief Tells if the bomb should explode
         *
         *  Returns true if the bomb's fuse has burned out.
         *  Otherwise returns false.
         *
         *  \return true if the fuse has burned out, else false.
         */
        bool Explode() const;
        /**
         *  \brief Draws the bomb on given SDL_Renderer
         *
         *  Draws the bomb on the map according to it's coordinates.
         *  \param renderer represents the SDL_Renderer on which the bomb
         *         will be drawn on.
         *
         *  \return void
         */
        void Draw(SDL_Renderer* renderer) const;

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
