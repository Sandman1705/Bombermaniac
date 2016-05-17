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

ExplosionManager* Relay::GetExplosionManager() const
{
    return m_explosion_manager;
}

void Relay::SetExplosionManager(ExplosionManager* val)
{
    m_explosion_manager = val;
}

BombManager* Relay::GetBombManager() const
{
    return m_bomb_manager;
}

void Relay::SetBombManager(BombManager* val)
{
    m_bomb_manager = val;
}

PlayerManager* Relay::GetPlayerManager() const
{
    return m_player_manager;
}

void Relay::SetPlayerManager(PlayerManager* val)
{
    m_player_manager = val;
}

EnemyManager* Relay::GetEnemyManager() const
{
    return m_enemy_manager;
}

void Relay::SetEnemyManager(EnemyManager* val)
{
    m_enemy_manager = val;
}
