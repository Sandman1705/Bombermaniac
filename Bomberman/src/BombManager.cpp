#include "BombManager.h"

#ifdef DEBUG_OUTPUT
#include <iostream>
#endif // DEBUG_OUTPUT

#include "WallDestroyer.h"

BombManager::BombManager(SDL_Texture* texture, unsigned int tile_size, ExplosionManager* explosion_manager, Map* level)
    : m_texture(texture), m_bomb_size(tile_size * 20 / 32), m_explosion_manager(explosion_manager), m_level(level), m_tile_size(tile_size)
{
    m_SrcR.x = 304;
    m_SrcR.y = 1;
    m_SrcR.w = 23;
    m_SrcR.h = 23;
}

BombManager::~BombManager()
{
    for(auto i = m_bombs.begin(); i != m_bombs.end(); ++i)
    {
        delete (*i);
        #ifdef DEBUG_OUTPUT
        std::cout << "Bomb deleted" << std::endl;
        #endif // DEBUG_OUTPUT
    }
}

void BombManager::AddBomb(Bomb *bomb)
{
    m_bombs.push_back(bomb);
}

void BombManager::MakeBomb(unsigned int fuse_duration, unsigned int x, unsigned int y, double intensity)
{
    Bomb* b = new Bomb(fuse_duration,m_texture,&m_SrcR,x,y,m_bomb_size,intensity);
    AddBomb(b);
}

void BombManager::BurnFuses()
{
    for(auto i = m_bombs.begin(); i != m_bombs.end();)
    {
        (*i)->BurnFuse();
        if((*i)->Explode())
        {
            unsigned int half_bomb_size = (*i)->Get_bomb_size() / 2;
            m_explosion_manager->MakeExplosion(1000, (*i)->Get_x()+half_bomb_size, (*i)->Get_y()+half_bomb_size, (*i)->Get_intensity());
            WallDestroyer wd(m_level,(*i)->Get_x()+half_bomb_size,(*i)->Get_y()+half_bomb_size,m_tile_size,(*i)->Get_intensity());
            delete (*i);
            i = m_bombs.erase(i);
        }
        else
            ++i;
    }
}

void BombManager::Draw(SDL_Renderer* renderer) const
{
    for(auto i = m_bombs.begin(); i != m_bombs.end(); ++i)
    {
        (*i)->Draw(renderer);
    }
}
