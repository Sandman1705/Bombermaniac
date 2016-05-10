#ifndef BOMBMANAGER_H
#define BOMBMANAGER_H

#include<list>
#include"Bomb.h"

class BombManager
{
    public:
        BombManager(SDL_Texture* texture, unsigned int bomb_size);
        ~BombManager();
        //TODO Copy constructor
        //TODO Operator=

        void AddBomb(Bomb *bomb);
        void MakeBomb(unsigned int fuse_duration, unsigned int x, unsigned int y);
        void BurnFuses();
        void Draw(SDL_Renderer* renderer);

    protected:

    private:
        std::list<Bomb*>    m_bombs;
        SDL_Texture*        m_texture;
        SDL_Rect            m_SrcR;
        unsigned int        m_bomb_size;
};

#endif // BOMBMANAGER_H
