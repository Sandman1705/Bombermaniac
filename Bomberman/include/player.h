#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include "Map.h"

class player
{
    public:
        player(SDL_Texture* tex);
        player(SDL_Texture* tex, unsigned int val_x, unsigned int val_y);
        virtual ~player();

        unsigned int Get_x() const;
        void Set_x(unsigned int val);
        unsigned int Get_y() const;
        void Set_y(unsigned int val);

        unsigned int Get_size_w() const;
        unsigned int Get_size_h() const;

        void player_move(int x, int y, Map *level);
        void Draw(SDL_Renderer* renderer);

    protected:

    private:
        unsigned int m_x;
        unsigned int m_y;
        unsigned int m_move_speed = 4;
        unsigned int m_player_size_w = 17;
        unsigned int m_player_size_h = 23;
        SDL_Texture* m_tex;
};

#endif // PLAYER_H
