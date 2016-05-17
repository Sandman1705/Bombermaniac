#include "Relay.h"
#include "ExplosionManager.h"
#include "BombManager.h"
#include "PlayerManager.h"
#include "EnemyManager.h"

Relay::Relay()
{

}

Relay::Relay(ExplosionManager *explosion_manager, BombManager *bomb_manager,
              PlayerManager *player_manager, EnemyManager *enemy_manager)
{
    m_explosion_manager = explosion_manager;
    m_bomb_manager = bomb_manager;
    m_player_manager = player_manager;
    m_enemy_manager = enemy_manager;
}

ExplosionManager* Relay::Get_explosion_manager() const
{
    return m_explosion_manager;
}

void Relay::Set_explosion_manager(ExplosionManager* val)
{
    m_explosion_manager = val;
}

BombManager* Relay::Get_bomb_manager() const
{
    return m_bomb_manager;
}

void Relay::Set_bomb_manager(BombManager* val)
{
    m_bomb_manager = val;
}

PlayerManager* Relay::Get_player_manager() const
{
    return m_player_manager;
}

void Relay::Set_player_manager(PlayerManager* val)
{
    m_player_manager = val;
}

EnemyManager* Relay::Get_enemy_manager() const
{
    return m_enemy_manager;
}

void Relay::Set_enemy_manager(EnemyManager* val)
{
    m_enemy_manager = val;
}
