#ifndef BOMBMANAGER_H
#define BOMBMANAGER_H

#include <list>
#include "Bomb.h"
#include "ExplosionManager.h"
#include "Map.h"

class BombManager
{
    public:
        BombManager(SDL_Texture* texture, unsigned int tile_size, ExplosionManager* explosion_manager, Map* level);
        ~BombManager();
        //TODO Copy constructor
        //TODO Operator=

        void AddBomb(Bomb *bomb);
        void MakeBomb(unsigned int fuse_duration, unsigned int x, unsigned int y, double intensity = 1.0);
        void BurnFuses();
        void Draw(SDL_Renderer* renderer) const;

    protected:

    private:
        std::list<Bomb*>        m_bombs;
        SDL_Texture*            m_texture;
        SDL_Rect                m_SrcR;
        unsigned int            m_bomb_size;
        ExplosionManager*       m_explosion_manager;
        Map*                    m_level;
        unsigned int            m_tile_size;
};

#endif // BOMBMANAGER_H
