#ifndef BOMBMANAGER_H
#define BOMBMANAGER_H

/**
 *  \file BombManager.h
 *
 *  Defines class BombManger which is used for keeping track on all bombs in
 *  the game
 *
 */

#include <list>
#include "Bomb.h"
#include "ExplosionManager.h"
#include "Map.h"

class EnemyManager;
class PlayerManager;

/** \class BombManager
 *  \brief Class which is used for keeping track of all the bombs in the game.
 *  \details This class contains the list of all bomb which are placed by the
 *           player. Has appropriate methods for adding bombs and drawing them.
 *           Also has an update method in the form of BurnFuses() which calls
 *           the appropriate update method for all bombs. Also keeps reference
 *           to ExplosionManager to which it sends signal for making new an
 *           explosion when one or more bombs have burned out their fuses.
 */
class BombManager
{
    public:
        /**
         *  \brief Constructor for BombManager
         *
         *  Makes an object of class BombManager according to given
         *  attributes
         *  \param texture pointer to SDL_texture object from which the texture
         *         will be taken for method Draw()
         *  \param tile_size represents the size of one tile of the map in
         *         pixels (which is required for proper implementation of method
         *         Draw())
         *  \param explosion_manager pointer to the explosion_manager of the
         *         game (which is needed for sending signals to that object to
         *         make new explosion)
         *  \param level pointer to the Map object of the game (which is needed
         *         for when the bombs destroy walls and make changes to the map)
         */
        BombManager(SDL_Texture* texture, unsigned int tile_size, ExplosionManager* explosion_manager, Map* level);
        ~BombManager();
        //TODO Copy constructor
        //TODO Operator=

        /**
         *  \brief Adds new Bomb to the list of bombs.
         *
         *  Adds new Bomb to the list of bombs so that it will be periodically
         *  updated and destroyed when it's fuse runs out. Will also make new
         *  Explosion and possibly destroy walls on the map or enemies or player
         *
         *  \param bomb pointer to object Bomb which will be added to the list
         *  \return void
         */
        void AddBomb(Bomb *bomb);
        /**
         *  \brief Makes new Bomb according to given parameters and adds it to
         *         the list of bombs.
         *
         *  Uses the given parameters and makes a new Bomb object and adds it to
         *  the list of bombs same as method AddBomb(Bomb* bomb). The bomb will
         *  be periodically updated and destroyed when it's fuse runs out.
         *
         *  \param fuse_duration duration of bombs fuse in millisecond
         *  \param x top left x coordinate of the bomb on the map
         *  \param y top left y coordinate of the bomb on the map
         *  \param intensity real value which represents the intensity of the
         *         bombs explosion after it's fuses burns out
         *  \return void
         */
        void MakeBomb(unsigned int fuse_duration, unsigned int x, unsigned int y, double intensity = 1.0);
        /**
         *  \brief Update function for class BombManager
         *
         *  Calls the update methods of all the bombs it keeps track of.
         *
         *  \return void
         */
        void Update();
        /**
         *  \brief Draw all the bombs it keeps track of on given SLD_Renderer
         *
         *  Calls Bomb::Draw() methods for all the bombs it keeps track of with
         *  the given SLD_Renderer so it will draw them on that same renderer.
         *  \param renderer represents the SDL_Renderer on which the bombs
         *         will be drawn on.
         *
         *  \return void
         */
        void Draw(SDL_Renderer* renderer) const;

        void SetEnemyManager(EnemyManager* enemy_manager) { m_enemy_manager = enemy_manager;}
        void SetPlayerManager(PlayerManager* player_manager) { m_player_manager = player_manager;}

    protected:

    private:
        std::list<Bomb*>        m_bombs;
        SDL_Texture*            m_texture;
        SDL_Rect                m_SrcR;
        unsigned int            m_bomb_size;
        ExplosionManager*       m_explosion_manager;
        Map*                    m_level;
        unsigned int            m_tile_size;
        EnemyManager*           m_enemy_manager;
        PlayerManager*          m_player_manager;
};

#endif // BOMBMANAGER_H
