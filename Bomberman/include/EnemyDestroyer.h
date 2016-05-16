#ifndef ENEMYDESTROYER_H
#define ENEMYDESTROYER_H

#include "Enemy.h"
#include "Player.h"

class EnemyDestroyer
{
    public:

        static void DestroyEnemy(Enemy* enemy,
                                 unsigned int start_x,
                                 unsigned int start_y,
                                 unsigned int tile_size,
                                 double intensity);
         static void DestroyPlayer(Player* player,
                                 unsigned int start_x,
                                 unsigned int start_y,
                                 unsigned int tile_size,
                                 double intensity);

    protected:

        static int Square(int x) { return x*x; }

    private:

        EnemyDestroyer();
};

#endif // ENEMYDESTROYER_H
