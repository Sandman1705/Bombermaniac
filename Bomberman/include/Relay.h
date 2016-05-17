#ifndef RELAY_H
#define RELAY_H

class ExplosionManager;
class BombManager;
class PlayerManager;
class EnemyManager;

class Relay
{
    public:
        Relay();
        Relay(ExplosionManager *explosion_manager, BombManager *bomb_manager,
              PlayerManager *player_manager, EnemyManager *enemy_manager);

        ExplosionManager* Get_explosion_manager() const;
        void Set_explosion_manager(ExplosionManager* val);

        BombManager* Get_bomb_manager() const;
        void Set_bomb_manager(BombManager* val);

        PlayerManager* Get_player_manager() const;
        void Set_player_manager(PlayerManager* val);

        EnemyManager* Get_enemy_manager() const;
        void Set_enemy_manager(EnemyManager* val);

    protected:

    private:
        ExplosionManager* m_explosion_manager;
        BombManager*      m_bomb_manager;
        PlayerManager*    m_player_manager;
        EnemyManager*     m_enemy_manager;

};

#endif // RELAY_H
