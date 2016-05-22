#ifndef ENEMYTWO_H
#define ENEMYTWO_H

#include <SDL.h>
#include <cstdlib>
#include <ctime>
#include "Relay.h"
#include "Timer.h"
#include "Player.h"
#include "Enemy.h"

class EnemyTwo : public Enemy
{
    public:
       public:
        /**
         *  \brief Constructor for EnemyTwo.
         *
         *  Makes an object of class EnemyTwo according to given attributes.
         *  \param tex pointer to SDL_texture object from which the texture
         *         will be taken for method Draw()
         *  \param tile_size size of one tile on map
         *  \param val_x coordinate of the enemy on the map
         *  \param val_y coordinate of the enemy on the map
         *
         */
        EnemyTwo(SDL_Texture* tex, unsigned int tile_size, unsigned int val_x = 1, unsigned int val_y = 1);

        void Draw(SDL_Renderer* renderer);

    protected:

    private:
};

#endif // ENEMYTWO_H
