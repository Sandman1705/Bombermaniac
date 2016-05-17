#ifndef RELAY_H
#define RELAY_H

class ExplosionManager;
class BombManager;
class PlayerManager;
class EnemyManager;
class Map;

class Relay
{
    public:
        Relay();
        Relay(ExplosionManager *explosion_manager,
              BombManager *bomb_manager,
              PlayerManager *player_manager,
              EnemyManager *enemy_manager,
              Map* map_level);

        ExplosionManager* GetExplosionManager() const;
        void SetExplosionManager(ExplosionManager* val);

        BombManager* GetBombManager() const;
        void SetBombManager(BombManager* val);

        PlayerManager* GetPlayerManager() const;
        void SetPlayerManager(PlayerManager* val);

        EnemyManager* GetEnemyManager() const;
        void SetEnemyManager(EnemyManager* val);

        Map* GetMap() const;
        void SetMap(Map* val);

    protected:

    private:
        ExplosionManager* m_explosion_manager;
        BombManager*      m_bomb_manager;
        PlayerManager*    m_player_manager;
        EnemyManager*     m_enemy_manager;
        Map*              m_map;

};

#endif // RELAY_H
