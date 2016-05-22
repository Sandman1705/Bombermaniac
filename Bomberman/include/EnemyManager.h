#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

/**
 *  \file EnemyManager.h
 *
 *  Defines class EnemyManger which is used for keeping track on all enemies in
 *  the game
 *
 */

#include <list>
#include "DisplayElement.h"
#include "Relay.h"
#include "Enemy.h"
#include "Player.h"
#include "Destroyer.h"
#include "EnemyOne.h"

/** \class EnemyManager
 *  \brief Class which is used for keeping track of all the enemies in the game.
 *  \details This class contains the list of all enemies.
 *           Has appropriate methods for adding enemies and drawing them.
 *           Also has an update method which calls the appropriate update
 *           method for all enemies.
 */
class EnemyManager : public DisplayElement
{
    public:
        /**
         *  \brief Constructor for EnemyManager
         *
         *  Makes an object of class EnemyManager according to given
         *  attributes
         *  \param texture pointer to SDL_texture object from which the texture
         *         will be taken for method Draw()
         *  \param tile_size represents the size of one tile of the map in
         *         pixels (which is required for proper implementation of method
         *         Draw())
         *  \param relay pointer to the Relay object of the game
         */
        EnemyManager(SDL_Texture* texture, unsigned int tile_size, Relay *relay);
        virtual ~EnemyManager();

        /**
         *  \brief Adds new Enemy to the list of enemies.
         *
         *  Adds new Enemy to the list of enemies so that it will be periodically
         *  updated and destroyed when the player kills them with bombs.
         *
         *  \param enemy pointer to object Enemy which will be added to the list
         *
         *  \return void
         */
        void AddEnemy(Enemy *enemy);

        /**
         *  \brief Makes new Enemy according to given parameters and adds it to
         *         the list of enemies.
         *
         *  Uses the given parameters and makes a new Enemy object and adds it
         *  to the list of enemies same as method AddEnemy(). The enemy will
         *  be periodically updated and destroyed.
         *
         *  \param x top left x coordinate of the enemy on the map
         *  \param y top left y coordinate of the enemy on the map
         *
         *  \return void
         */
        void MakeEnemy(unsigned int x = 0, unsigned int y = 0);

        void MakeEnemyOne(unsigned int x = 0, unsigned int y = 0);

         /**
         *  \brief Draw all the enemies it keeps track of on given SLD_Renderer
         *
         *  Calls Enemy::Draw() methods for all the enemies it keeps track of with
         *  the given SLD_Renderer so it will draw them on that same renderer.
         *  \param renderer represents the SDL_Renderer on which the enemies
         *         will be drawn on.
         *
         *  \return void
         */
        void Draw(SDL_Renderer* renderer) const;

        /**
         *  \brief Update function for class EnemyManager
         *
         *  Calls the update methods of all the enemies it keeps track of.
         *
         *  \return void
         */
        void Update();

        void KillEnemies(unsigned int x, unsigned int y, double intensity);

    protected:

    private:
    std::list<Enemy*>       m_enemies;
    Relay*                  m_relay;
    unsigned int            m_tile_size;
};

#endif // ENEMYMANAGER_H
