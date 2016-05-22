#include "EnemyManager.h"
#include "PlayerManager.h"
#include <fstream>
#include <iostream>

EnemyManager::EnemyManager(std::string path_to_file, SDL_Texture* texture, unsigned int tile_size, Relay *relay)
    : DisplayElement(texture)
{
    m_texture = texture;
    m_tile_size = tile_size;
    m_relay = relay;

    std::fstream fs;
    fs.open (path_to_file, std::fstream::in);

    if (!fs.is_open())
    {
        exit(EXIT_FAILURE);
    }

    fs >> m_enemies_numb;

    for (unsigned i=0; i<m_enemies_numb; ++i)
    {
        unsigned int id, x=0, y=0;
        fs >> id >> x >> y;

        switch(id)
        {
            case 1:
                MakeEnemyOne(x, y);
               break;
            case 2:
                MakeEnemyTwo(x, y);
                break;
            case 3:
                MakeEnemy(x, y);
                break;
            default:
                break;
        }
    }

    fs.close();
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
        Destroyer::DestroyEnemy(*i, x, y, m_tile_size, intensity);
        if((*i)->GetHealth() == 0)
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

void EnemyManager::MakeEnemyOne(unsigned int x, unsigned int y)
{
    Enemy* e = new EnemyOne(m_texture, m_tile_size,x, y);
    AddEnemy(e);
}

void EnemyManager::MakeEnemyTwo(unsigned int x, unsigned int y)
{
    Enemy* e = new EnemyTwo(m_texture, m_tile_size, x, y);
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
        for(auto j = m_relay->GetPlayerManager()->GetPlayers()->begin(); j != m_relay->GetPlayerManager()->GetPlayers()->end(); ++j)
        (*i)->Update(m_relay, *j);
    }
}
