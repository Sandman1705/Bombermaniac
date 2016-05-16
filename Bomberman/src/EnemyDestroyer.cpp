#include "EnemyDestroyer.h"
#include <cmath>

EnemyDestroyer::EnemyDestroyer()
{
}


void EnemyDestroyer::DestroyEnemy(Enemy* enemy,
                                  unsigned int start_x,
                                  unsigned int start_y,
                                  unsigned int tile_size,
                                  double intensity)
{
    unsigned int enemy_center_x = enemy->Get_x() + enemy->Get_size_w() / 2;
    unsigned int enemy_center_y = enemy->Get_y() + enemy->Get_size_h() / 2;
    double distance = std::sqrt( Square(start_x-enemy_center_x) + Square(start_y-enemy_center_y) );

    if (distance < tile_size * intensity / 2)
        enemy->Set_health(0);
}
