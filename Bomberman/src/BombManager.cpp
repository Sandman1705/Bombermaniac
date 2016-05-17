#include "BombManager.h"

#ifdef DEBUG_OUTPUT_BOMB
#include <iostream>
#endif // DEBUG_OUTPUT_BOMB

#include "WallDestroyer.h"
#include "ExplosionManager.h"
#include "EnemyManager.h"
#include "PlayerManager.h"

BombManager::BombManager(SDL_Texture* texture,
                         unsigned int tile_size,
                         Relay* relay)
    : m_texture(texture),
      m_bomb_size(tile_size * 20 / 32),
      m_tile_size(tile_size),
      m_relay(relay)
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
        #ifdef DEBUG_OUTPUT_BOMB
        std::cout << "Bomb deleted" << std::endl;
        #endif // DEBUG_OUTPUT_BOMB
    }
}

void BombManager::AddBomb(Bomb *bomb)
{
    m_bombs.push_back(bomb);
}

void BombManager::MakeBomb(unsigned int fuse_duration, unsigned int x, unsigned int y, double intensity)
{
    Bomb* b = new Bomb(fuse_duration,m_texture,x,y,m_bomb_size,intensity);
    AddBomb(b);
}

void BombManager::Update()
{
    for(auto i = m_bombs.begin(); i != m_bombs.end();)
    {
        (*i)->Update();
        if((*i)->Explode())
        {
            unsigned int half_bomb_size = (*i)->GetBombSize() / 2;
            m_relay->GetExplosionManager()->MakeExplosion(1000, (*i)->GetX()+half_bomb_size, (*i)->GetY()+half_bomb_size, (*i)->GetIntensity());
            WallDestroyer wd(m_relay->GetMap(), (*i)->GetX()+half_bomb_size, (*i)->GetY()+half_bomb_size, m_tile_size, (*i)->GetIntensity());
            m_relay->GetEnemyManager()->KillEnemies((*i)->GetX()+half_bomb_size, (*i)->GetY()+half_bomb_size, (*i)->GetIntensity());
            m_relay->GetPlayerManager()->KillPlayer((*i)->GetX()+half_bomb_size, (*i)->GetY()+half_bomb_size, (*i)->GetIntensity());
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
