#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include "Map.h"
#include "BombManager.h"

class Player
{
    public:
        Player(SDL_Texture* tex, unsigned int tile_size, BombManager *bomb_manager);
        Player(SDL_Texture* tex, unsigned int tile_size, unsigned int val_x, unsigned int val_y, BombManager *bomb_manager);
        virtual ~Player();

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

        void player_move(int x, int y, Map *level);
        void Draw(SDL_Renderer* renderer);
        void place_bomb();

    protected:

    private:
        enum Direction
        {
              LEFT = 0,
              RIGHT = 1,
              UP = 2,
              DOWN = 3
        };
        Direction m_direction;
        int m_status;
        unsigned int m_x;
        unsigned int m_y;
        unsigned int m_move_speed = 4;
        unsigned int m_player_size_w = 17;
        unsigned int m_player_size_h = 23;
        SDL_Texture* m_tex;
        unsigned int m_tile_size;
        BombManager* m_bomb_manager;
};

#endif // PLAYER_H
