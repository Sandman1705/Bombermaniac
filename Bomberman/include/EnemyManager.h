#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include <list>
#include "Map.h"
#include "Enemy.h"
#include "Player.h"

class EnemyManager
{
    public:
        EnemyManager(SDL_Texture* texture, unsigned int tile_size, Map* level,
                     Player* player);
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
    Player*                 m_player;
    unsigned int            m_tile_size;
};

#endif // ENEMYMANAGER_H
