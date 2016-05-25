#ifndef ENEMYTHREE_H
#define ENEMYTHREE_H

/**
 *  \file EnemyThree.h
 *
 *  Defines class EnemyThree which represents an type of enemy.
 *
 */

#include <SDL.h>
#include <cstdlib>
#include <ctime>
#include "Utility/Relay.h"
#include "Utility/Timer.h"
#include "Entity/Player.h"
#include "Entity/Enemy.h"

/** \class EnemyThree
 *  \brief class which represents an type of enemy and inherits class Enemy
 *  \details This class contains all properties of an enemy like its
 *           coordinates on a map, its size, direction where its going
 *           as well as its speed. Also contains a method Draw()
 *           which draws him on a proper place on map and inherited methods
 *           like  EnemyMove() for moving around the map and Update() for
 *           refreshing its position.
 */

class EnemyThree : public Enemy
{
    public:
        /**
         *  \brief Constructor for EnemyThree.
         *
         *  Makes an object of class EnemyThree according to given attributes.
         *  \param tex pointer to SDL_texture object from which the texture
         *         will be taken for method Draw()
         *  \param tile_size size of one tile on map
         *  \param val_x x coordinate of the enemy on the map
         *  \param val_y y coordinate of the enemy on the map
         *
         */
        EnemyThree(SDL_Texture* tex, unsigned int tile_size, unsigned int val_x = 1, unsigned int val_y = 1);

        /**
         *  \brief Draws the enemy on given SDL_Renderer.
         *
         *  Draws the enemy on the map according to its coordinates.
         *  \param renderer represents SDL_Renderer on which the enemy
         *  will be drawn on
         *
         *  \return void
         */
        void Draw(SDL_Renderer* renderer);

        void Update(Relay *relay,Player *player);
        void EnemyThreeDirection(Relay *relay);
        void ChasePlayer(Player * player, Relay *relay);
        bool DirectionCheck(Direction d, Relay *relay);
    protected:

    private:
        bool m_chase = false;
};

#endif // ENEMYTHREE_H
