#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include <list>
#include "Map.h"
#include "Enemy.h"

class EnemyManager
{
    public:
        EnemyManager(SDL_Texture* texture, unsigned int tile_size, Map* level);
        virtual ~EnemyManager();

        void AddEnemy(Enemy *enemy);
        void MakeEnemy(unsigned int x = 0, unsigned int y = 0);
        void Draw(SDL_Renderer* renderer) const;
        void Update();

    protected:

    private:
    std::list<Enemy*>       m_enemies;
    SDL_Texture*            m_texture;
    Map*                    m_level;
    unsigned int            m_tile_size;
};

#endif // ENEMYMANAGER_H
