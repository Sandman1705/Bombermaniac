#ifndef ENEMYONE_H
#define ENEMYONE_H

/**
 *  \file EnemyOne.h
 *
 *  Defines class EnemyOne which represents an enemy.
 *
 */

#include <SDL.h>
#include <cstdlib>
#include <ctime>
#include "Relay.h"
#include "Timer.h"
#include "Player.h"
#include "Enemy.h"

/** \class EnemyOne
 *  \brief class which represents an enemy
 *  \details This class contains all properties of an enemy like its
 *           coordinates on a map, its size, direction where its going
 *           as well as its speed. Also contains a method Draw()
 *           which draws him on a proper place on map, method enemy_move()
 *           for moving around the map and update() for
 *           refreshing its position.
 */

class EnemyOne : public Enemy
{
    public:
        /**
         *  \brief Constructor for EnemyOne.
         *
         *  Makes an object of class EnemyOne according to given attributes.
         *  \param tex pointer to SDL_texture object from which the texture
         *         will be taken for method Draw()
         *  \param tile_size size of one tile on map
         *  \param val_x coordinate of the enemy on the map
         *  \param val_y coordinate of the enemy on the map
         *
         */
        EnemyOne(SDL_Texture* tex, unsigned int tile_size, unsigned int val_x = 1, unsigned int val_y = 1);

        void Draw(SDL_Renderer* renderer);

    protected:

    private:
};

#endif // ENEMYONE_H
