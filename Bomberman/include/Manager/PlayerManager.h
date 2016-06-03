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
#include <list>
#include "Display/DisplayElement.h"
#include "Entity/Player.h"
#include "Utility/Timer.h"
#include "Utility/Relay.h"

/** \class PlayerManager
 *  \brief Class which is used for keeping track of player in the game.
 *  \details This class has appropriate methods for making a player and
 *           drawing him. Also has an update method which calls the
 *           appropriate update method for player, and keeps reference
 *           to BombManager to which it sends signal for making a new bomb.
 */

class PlayerManager : public DisplayElement
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
         *  \param relay pointer to the relay of the
         *         game (which is needed for getting bomb_manager for sending
         *         signals to that object to make new bomb)
         *  \param keyboard_input pointer to KeyboardInput object of the game
         *         (which is used to keep track of input given by the user)
         */
    public:
        PlayerManager(std::string path_to_file, SDL_Texture* texture, unsigned int tile_size, Relay *relay);
        ~PlayerManager();

        std::list<Player*>* GetPlayers();

        bool AreAllDead() const;

         /**
         *  \brief Adds new Player to the list of players.
         *
         *  Adds new Player to the list of players so that it will be periodically
         *  updated and destroyed when the enemy kills them.
         *
         *  \param player pointer to object Player which will be added to the list
         *
         *  \return void
         */
        void AddPlayer(Player *player);

         /**
         *  \brief Makes new Player according to given parameters.
         *
         *  Uses the given parameters and makes a new Player object.
         *  The player will be periodically updated and destroyed when runs
         *  out of lives.
         *  \param player_id ID of the player
         *  \param x top left x coordinate of the player on the map
         *  \param y top left y coordinate of the player on the map
         *
         *  \return void
         */
        void MakePlayer(unsigned int player_id = 0, unsigned int x = 1, unsigned int y = 1);

        /**
         *  \brief Draw the player it keeps track of on given SLD_Renderer.
         *
         *  Calls Player::Draw() method for the player it keeps track of with
         *  the given SLD_Renderer so it will draw them on that same renderer.
         *
         *  \param renderer represents the SDL_Renderer on which the player
         *         will be drawn on.
         *
         *  \return void
         */
        void Draw(SDL_Renderer* renderer) const;

        void DrawScore(SDL_Renderer* renderer, unsigned int player_id, unsigned int lives) const;

        /**
         *  \brief Update function for class PlayerManager.
         *
         *  Calls the update method of player it keeps track of.
         *
         *  \return void
         */
        void Update();

        /**
         *  \brief Kills the player if bomb is near enough.
         *
         *  Calls Destroyer::DestroyPlayer() method that for every player it keeps track of
         *  decreases health if player is near the bomb.
         *
         *  \param x x coordinate of the center of the bomb on the map
         *  \param y y coordinate of the center of the bomb on the map
         *  \param intensity intensity of the bomb
         *
         *  \return void
         */
        void KillPlayer(unsigned int x, unsigned int y, double intensity);

    protected:

    private:
    unsigned int             m_death_time;
    unsigned int             m_players_numb;
    Timer                    m_timer;
    std::list<Player*>       m_players;
    Relay*                   m_relay;
    unsigned int             m_tile_size;
};

#endif // PLAYERMANAGER_H
