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
#include <vector>
#include "Display/DisplayElement.h"
#include "Entity/Player.h"
#include "Utility/Timer.h"
#include "Utility/Relay.h"
#include "SDL_mixer.h"

/** \class PlayerManager
 *  \brief Class which is used for keeping track of player in the game.
 *  \details This class has appropriate methods for making a player and
 *           drawing him. Also has an update method which calls the
 *           appropriate update method for player, and keeps reference
 *           to BombManager to which it sends signal for making a new bomb.
 */

class PlayerManager : public DisplayElement
{
    public:
        /**
         *  \brief Constructor for PlayerManager
         *
         *  Makes an object of class PlayerManager according to given
         *  parameters
         *
         *  \param path_to_file string path to file in which are
         *         coordinates for players
         *  \param texture pointer to SDL_texture object from which the texture
         *         will be taken for method Draw()
         *  \param tile_size represents the size of one tile of the map in
         *         pixels (which is required for proper implementation of method
         *         Draw())
         *  \param relay pointer to the relay of the
         *         game (which is needed for getting bomb_manager for sending
         *         signals to that object to make new bomb)
         */
        PlayerManager(std::string path_to_file, SDL_Texture* texture, unsigned int tile_size, Relay *relay);
        ~PlayerManager();
        PlayerManager(const PlayerManager& other) = delete; /**< \brief Default copy constructor is disabled */
        PlayerManager& operator=(const PlayerManager&) = delete; /**< \brief Default operator = is disabled */

        std::vector<Player*>* GetPlayers();
        Player* GetPlayerById(int id);

        /**
         *  \brief Check if all players are dead.
         *
         *  Checks for each player if it's alive and returns true
         *  if they are all alive.
         *
         *  \return bool
         */
        bool AreAllDead() const;

        /**
         *  \brief Check if level is completed by players.
         *
         *  Checks if level is completed. Level is completed if
         *  all players completed the level or if at least one is
         *  and others are dead.
         *
         *  \return bool
         */
        bool AreAllCompleted() const;

         /**
         *  \brief Adds new Player to the list of players.
         *
         *  Adds new Player to the list of players so that it will be
         *  periodically updated and destroyed when the enemy kills them.
         *
         *  \param player pointer to Player which will be added to the list
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

        /**
         *  \brief Draws the life board it keeps track of on given SLD_Renderer.
         *
         *  Draws lives of the player on the given SLD_Renderer so it
         *  will draw them on that same renderer.
         *
         *  \param renderer represents the SDL_Renderer on which the player
         *         will be drawn on.
         *  \param player_id represents the ID of the player
         *  \param lives represents number of lives that are going to be drawn
         *
         *  \return void
         */
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
         *  Calls Destroyer::DestroyPlayer() method that for every player it
         *  keeps track of, decreases health if player is near the bomb.
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
    std::vector<Player*>       m_players;
    Relay*                   m_relay;
    unsigned int             m_tile_size;
    Mix_Chunk*               m_kill_sound;
};

#endif // PLAYERMANAGER_H
