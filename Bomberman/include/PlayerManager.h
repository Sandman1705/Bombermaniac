#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

/**
 *  \file PlayerManager.h
 *
 *  Defines class PlayerManger which is used for keeping track on player in
 *  the game
 *
 */

#include <SDL.h>
#include "Player.h"
#include "Map.h"
#include "Timer.h"

/** \class PlayerManager
 *  \brief Class which is used for keeping track of player in the game.
 *  \details This class has appropriate methods for making a player and
 *           drawing him. Also has an update method which calls the
 *           appropriate update method for player, and keeps reference
 *           to BombManager to which it sends signal for making a new bomb.
 */

class PlayerManager
{
    /**
         *  \brief Constructor for PlayerManager
         *
         *  Makes an object of class PlayerManager according to given
         *  attributes
         *  \param texture pointer to SDL_texture object from which the texture
         *         will be taken for method Draw()
         *  \param tile_size represents the size of one tile of the map in
         *         pixels (which is required for proper implementation of method
         *         Draw())
         *  \param bomb_manager pointer to the bomb_manager of the
         *         game (which is needed for sending signals to that object to
         *         make new bomb)
         *  \param keyboard_input pointer to KeyboardInput object of the game
         *         (which is used to keep track of input given by the user)
         *  \param level pointer to the Map object of the game
         */
    public:
        PlayerManager(SDL_Texture* texture, unsigned int tile_size, BombManager *bomb_manager,
               KeyboardInput *keyboard_input, Map *level);

        Player* Get_player() const;

         /**
         *  \brief Makes new Player according to given parameters.
         *
         *  Uses the given parameters and makes a new Player object.
         *  The player will be periodically updated and destroyed when runs
         *  out of lives.
         *
         *  \param x top left x coordinate of the player on the map
         *  \param y top left y coordinate of the player on the map
         *
         *  \return void
         */
        void MakePlayer(unsigned int x = 0, unsigned int y = 0);

        /**
         *  \brief Draw the player it keeps track of on given SLD_Renderer
         *
         *  Calls Player::Draw() method for the player it keeps track of with
         *  the given SLD_Renderer so it will draw them on that same renderer.
         *
         *  \param renderer represents the SDL_Renderer on which the player
         *         will be drawn on.
         *
         *  \return void
         */
        void Draw(SDL_Renderer* renderer);

        /**
         *  \brief Update function for class PlayerManager
         *
         *  Calls the update method of player it keeps track of.
         *
         *  \return void
         */
        void Update();
    protected:

    private:
    unsigned int    m_alive=1;
    unsigned int    m_lives=3;
    unsigned int    m_death_time;
    Timer           m_timer;
    Player*         m_player;
    SDL_Texture*    m_texture;
    Map*            m_level;
    BombManager*    m_bomb_manager;
    KeyboardInput*  m_keyboard_input;
    unsigned int    m_tile_size;
};

#endif // PLAYERMANAGER_H
