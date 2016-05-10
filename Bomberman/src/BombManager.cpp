#include "BombManager.h"
#include <iostream>

BombManager::BombManager(SDL_Texture* texture, unsigned int bomb_size)
    : m_texture(texture), m_bomb_size(bomb_size)
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
    }
}

void BombManager::AddBomb(Bomb *bomb)
{
    m_bombs.push_back(bomb);
}

void BombManager::MakeBomb(unsigned int fuse_duration, unsigned int x, unsigned int y)
{
    Bomb* b = new Bomb(fuse_duration,m_texture,&m_SrcR,x,y,m_bomb_size);
    AddBomb(b);
}

void BombManager::BurnFuses()
{
    for(auto i = m_bombs.begin(); i != m_bombs.end();)
    {
        (*i)->BurnFuse();
        if((*i)->Explode())
        {
            delete (*i);
            i = m_bombs.erase(i);
        }
        else
            ++i;
    }
}

void BombManager::Draw(SDL_Renderer* renderer)
{
    for(auto i = m_bombs.begin(); i != m_bombs.end(); ++i)
    {
        (*i)->Draw(renderer);
    }
}
