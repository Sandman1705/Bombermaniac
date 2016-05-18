#include "EnemyManager.h"
#include "PlayerManager.h"

EnemyManager::EnemyManager(SDL_Texture* texture, unsigned int tile_size, Relay *relay)
    : DisplayElement(texture)
{
    m_texture = texture;
    m_tile_size = tile_size;
    m_relay = relay;
}

EnemyManager::~EnemyManager()
{
    for(auto i = m_enemies.begin(); i != m_enemies.end(); ++i)
    {
        delete (*i);
    }
}

void EnemyManager::KillEnemies(unsigned int x, unsigned int y, double intensity)
{
    for(auto i = m_enemies.begin(); i != m_enemies.end();)
    {
        EnemyDestroyer::DestroyEnemy(*i, x, y, m_tile_size, intensity);
        if((*i)->Get_health() == 0)
        {
            delete (*i);
            i = m_enemies.erase(i);
        }
        else
            ++i;
    }
}

void EnemyManager::AddEnemy(Enemy *enemy)
{
    m_enemies.push_back(enemy);
}

void EnemyManager::MakeEnemy(unsigned int x, unsigned int y)
{
    Enemy* e = new Enemy(m_texture, m_tile_size, x, y);
    AddEnemy(e);
}

void EnemyManager::Draw(SDL_Renderer* renderer) const
{
    for(auto i = m_enemies.begin(); i != m_enemies.end(); ++i)
    {
        (*i)->Draw(renderer);
    }
}

void EnemyManager::Update()
{
    for(auto i = m_enemies.begin(); i != m_enemies.end(); ++i)
    {
        (*i)->Update(m_relay, m_relay->GetPlayerManager()->GetPlayer());
    }
}
