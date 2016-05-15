#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include "Player.h"
#include "Map.h"
#include "Timer.h"

class PlayerManager
{
    public:
        PlayerManager(SDL_Texture* texture, unsigned int tile_size, BombManager *bomb_manager,
               KeyboardInput *keyboard_input, Map *level);

        Player* Get_player() const;

        void MakePlayer(unsigned int x = 0, unsigned int y = 0);
        void Draw(SDL_Renderer* renderer);
        void Update();
    protected:

    private:
    unsigned int    m_alive=1;
    unsigned int    m_death_time;
    Timer           m_timer;
    Player*         m_player;
    SDL_Texture*    m_texture;
    Map*            m_level;
    BombManager*    m_bomb_manager;
    KeyboardInput*  m_keyboard_input;
    unsigned int    m_tile_size;
};

#endif // PLAYERMANAGER_H
