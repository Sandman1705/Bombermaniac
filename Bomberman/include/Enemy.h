#ifndef ENEMY_H
#define ENEMY_H

class Enemy
{
    public:
        Enemy(SDL_Texture* tex, unsigned int tile_size);
        Enemy(SDL_Texture* tex, unsigned int tile_size, unsigned int val_x, unsigned int val_y);
        virtual ~Enemy();

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

        void enemy_move(int x, int y, Map *level);
        void Draw(SDL_Renderer* renderer);

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
        unsigned int m_enemy_size_w = 17;
        unsigned int m_enemy_size_h = 23;
        SDL_Texture* m_tex;
        unsigned int m_tile_size;
};

#endif // ENEMY_H
