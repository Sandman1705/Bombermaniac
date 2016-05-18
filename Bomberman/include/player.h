#ifndef PLAYER_H
#define PLAYER_H

/**
 *  \file Player.h
 *
 *  Defines class Player which represents a player.
 *
 */

#include <SDL.h>
#include "Relay.h"
#include "KeyboardInput.h"
#include "Timer.h"

/** \class Player
 *  \brief class which represents a player
 *  \details This class contains all properties of a player like its
 *           coordinates on a map, its size, direction where its going,
 *           its speed as well as some information about bombs.
 *           Also contains a method Draw() which draws him on a proper place on
 *           map, method player_move() for moving around the map, update()
 *           for refreshing its position and place_bomb() for
 *           placing bombs on map.
 */

class Player
{
    public:
        /**
         *  \brief Constructor for Player.
         *
         *  Makes an object of class Player according to given attributes.
         *  \param tex pointer to SDL_texture object from which the texture
         *         will be taken for method Draw()
         *  \param tile_size size of one tile on map
         *  \param relay for getting bomb_manager with list of bombs with
         *         methods for management
         *  \param keyboard_input pointer to KeyboardInput object of the game
         *         (which is used to keep track of input given by the user)
         *  \param val_x coordinate of the player on the map
         *  \param val_y coordinate of the player on the map
         *
         */
        Player(SDL_Texture* tex, unsigned int tile_size, Relay *relay,
               KeyboardInput *keyboard_input, unsigned int val_x = 0, unsigned int val_y = 0);

        unsigned int GetX() const;
        void SetX(unsigned int val);
        unsigned int GetY() const;
        void SetY(unsigned int val);

        unsigned int GetSizeW() const;
        unsigned int GetSizeH() const;

        unsigned int GetStatus() const;
        void SetStatus(unsigned int s);

        unsigned int GetAlive() const;
        void SetAlive(unsigned int a);

        unsigned int GetLives() const;
        void SetLives(unsigned int l);

        unsigned int GetDirection() const;
        void SetDirection(int d);

        unsigned int GetHealth() const;
        void SetHealth(unsigned int h);

        void SetKeycodes(SDL_Keycode up, SDL_Keycode down, SDL_Keycode left, SDL_Keycode right);

        /**
         *  \brief Function that implements movement for player.
         *
         *  Updates the position of player on the map according to it's
         *  parameters that depend on keys that player used.
         *  \param x value that represents where player wishes to go
         *  relative to its current position on x axis
         *  \param y value that represents where player wishes to go
         *  relative to its current position on y axis
         *  \param level pointer to Map object of the game
         *
         *  \return void
         */
        void PlayerMove(int x, int y);

        /**
         *  \brief Draws the player on given SDL_Renderer.
         *
         *  Draws the player on the map according to its coordinates.
         *  \param renderer represents SDL_Renderer on which the player
         *  will be drawn on
         *
         *  \return void
         */
        void Draw(SDL_Renderer* renderer);

        /**
         *  \brief Places the bomb on the map.
         *
         *  Places the bomb on map on player's current position.
         *
         *  \return void
         */
        void PlaceBomb();

        /**
         *  \brief Updates player's position on map.
         *
         *  Updates player's position and calls appropriate actions according
         *  to KeyboardInput of user.
         *
         *  \return void
         */
        void Update();

    protected:

    private:
        enum Direction
        {
              LEFT = 0,
              RIGHT = 1,
              UP = 2,
              DOWN = 3
        };
        Direction      m_direction;
        bool           m_bomb_ready = false;
        int            m_status;
        Timer          m_timer;
        unsigned int   m_lives=3;
        unsigned int   m_alive = 1;
        unsigned int   m_health = 100; //percent
        unsigned int   m_speed = 100;
        unsigned int   m_x;
        unsigned int   m_y;
        unsigned int   m_move_speed = 4;
        unsigned int   m_player_size_w = 17;
        unsigned int   m_player_size_h = 23;
        SDL_Texture*   m_tex;
        unsigned int   m_tile_size;
        Relay*         m_relay;
        KeyboardInput* m_keyboard_input;
        SDL_Keycode    m_space = SDLK_SPACE;
        SDL_Keycode    m_left = SDLK_LEFT;
        SDL_Keycode    m_right = SDLK_RIGHT;
        SDL_Keycode    m_up = SDLK_UP;
        SDL_Keycode    m_down = SDLK_DOWN;

};

#endif // PLAYER_H
