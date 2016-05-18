#ifndef ENEMY_H
#define ENEMY_H

/**
 *  \file Enemy.h
 *
 *  Defines class Enemy which represents an enemy.
 *
 */

#include <SDL.h>
#include <cstdlib>
#include <ctime>
#include "Relay.h"
#include "Timer.h"
#include "Player.h"

/** \class Enemy
 *  \brief class which represents an enemy
 *  \details This class contains all properties of an enemy like its
 *           coordinates on a map, its size, direction where its going
 *           as well as its speed. Also contains a method Draw()
 *           which draws him on a proper place on map, method enemy_move()
 *           for moving around the map and update() for
 *           refreshing its position.
 */

class Enemy
{
    public:
        /**
         *  \brief Constructor for Enemy.
         *
         *  Makes an object of class Enemy according to given attributes.
         *  \param tex pointer to SDL_texture object from which the texture
         *         will be taken for method Draw()
         *  \param tile_size size of one tile on map
         *  \param val_x coordinate of the enemy on the map
         *  \param val_y coordinate of the enemy on the map
         *
         */
        Enemy(SDL_Texture* tex, unsigned int tile_size, unsigned int val_x = 0, unsigned int val_y = 0);

        unsigned int Get_x() const;
        void Set_x(unsigned int val);
        unsigned int Get_y() const;
        void Set_y(unsigned int val);

        unsigned int Get_size_w() const;
        unsigned int Get_size_h() const;

        unsigned int Get_status() const;
        void Set_status(int s);

        unsigned int Get_direction() const;
        void Set_direction(int d);

        unsigned int Get_health() const;
        void Set_health(int h);

        /**
        *  \brief Function that implements movement for enemy.
        *
        *  Updates the position of enemy on the map according to
        *  method update().
        *
        *  \param relay pointer to Relay object of the game
        *
        *  \return void
        */
        void EnemyMove(Relay *relay);

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

        /**
         *  \brief Updates enemy's position on map.
         *
         *  Calculates where enemy should go and updates enemy's position
         *  on map accordingly and calls appropriate actions.
         *
         *  \param relay pointer to Relay object of the game
         *  \param player pointer to Player object of the game
         *
         *  \return void
         */
        void Update(Relay *relay, Player *player);

         /**
         *  \brief Checks if enemy touched player.
         *
         *  Calculates if there was a collision between
         *  enemy and player.
         *
         *  \param player_x x coordinate of the player
         *  \param player_y y coordinate of the player
         *
         *  \return bool
         */
        bool Touch(unsigned int player_x, unsigned int player_y);

    protected:

    private:
        enum Direction
        {
              LEFT = 0,
              RIGHT = 1,
              UP = 2,
              DOWN = 3
        };
        Direction    m_direction;
        int          m_walk_len = 0;
        Timer        m_timer;
        unsigned int m_speed = 100;
        unsigned int m_status;
        unsigned int m_health = 100; //percent
        unsigned int m_x;
        unsigned int m_y;
        unsigned int m_move_speed = 4;
        unsigned int m_enemy_size_w = 17;
        unsigned int m_enemy_size_h = 23;
        SDL_Texture* m_tex;
        unsigned int m_tile_size;
};

#endif // ENEMY_H
