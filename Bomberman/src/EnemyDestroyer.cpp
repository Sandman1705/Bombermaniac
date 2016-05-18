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

void EnemyDestroyer::DestroyPlayer(Player* player,
                                  unsigned int start_x,
                                  unsigned int start_y,
                                  unsigned int tile_size,
                                  double intensity)
{
    unsigned int player_center_x = player->GetX() + player->GetSizeW() / 2;
    unsigned int player_center_y = player->GetY() + player->GetSizeH() / 2;
    double distance = std::sqrt( Square(start_x-player_center_x) + Square(start_y-player_center_y) );

    if (distance < tile_size * intensity / 2)
        player->SetHealth(0);
}
