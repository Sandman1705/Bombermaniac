#include "Manager/PlayerManager.h"
#include "Destroyer/Destroyer.h"
#include "Constants/TextureScoreConstants.h"
#include <fstream>

PlayerManager::PlayerManager(std::string path_to_file, SDL_Texture* texture, unsigned int tile_size, Relay *relay)
    : DisplayElement(texture)
{
    m_tile_size = tile_size;
    m_relay = relay;
    m_timer.ResetTimer();

    std::fstream fs;
    fs.open (path_to_file, std::fstream::in);

    if (!fs.is_open())
    {
        exit(EXIT_FAILURE);
    }

    fs >> m_players_numb;

    for (unsigned i=0; i<m_players_numb; ++i)
    {
        unsigned int id, x=0, y=0;
        fs >> id >> x >> y;
        MakePlayer(id, x, y);
    }

    fs.close();
}

PlayerManager::~PlayerManager()
{
    for(auto i = m_players.begin(); i != m_players.end(); ++i)
    {
        delete (*i);
    }
}

void PlayerManager::MakePlayer(unsigned int player_id, unsigned int x, unsigned int y)
{
    Player *player = new Player(m_texture, m_tile_size, m_relay, player_id, x, y);
    m_players.push_back(player);
}

void PlayerManager::KillPlayer(unsigned int x, unsigned int y, double intensity)
{
    for(auto i = m_players.begin(); i != m_players.end(); ++i)
    {
        Destroyer::DestroyPlayer(*i, x, y, m_tile_size, intensity);
    }
}

void PlayerManager::AddPlayer(Player *player)
{
    m_players.push_back(player);
}

void PlayerManager::DrawScore(SDL_Renderer* renderer, unsigned int player_id, unsigned int lives) const
{
    SDL_Rect SrcR;
    SDL_Rect DestR;

    SrcR.y = TEXTURE_NUMB_Y;
    SrcR.w = TEXTURE_NUMB_SOURCE_W;
    SrcR.h = TEXTURE_NUMB_SOURCE_H;

    switch(lives)
    {
        case 0:
            SrcR.x = lives*TEXTURE_NUMB_SOURCE_W + TEXTURE_NUMB_X;
        break;

        case 1:
            SrcR.x = lives*TEXTURE_NUMB_SOURCE_W + TEXTURE_NUMB_X;
        break;

        case 2:
            SrcR.x = lives*TEXTURE_NUMB_SOURCE_W + TEXTURE_NUMB_X;
        break;

        case 3:
            SrcR.x = lives*TEXTURE_NUMB_SOURCE_W + TEXTURE_NUMB_X;
        break;
    }

    DestR.x = 0 + player_id*2*m_tile_size;
    DestR.y = 0;
    DestR.w = m_tile_size;
    DestR.h = m_tile_size;

    SDL_RenderCopy(renderer, m_texture, &SrcR, &DestR);

}

void PlayerManager::Draw(SDL_Renderer* renderer) const
{
    for(auto i = m_players.begin(); i != m_players.end(); ++i)
    {
        DrawScore(renderer, (*i)->GetID(), (*i)->GetLives());

        if( ((*i)->GetLives() != 0) && !((*i)->IsLevelCompleted()) )
            (*i)->Draw(renderer);
    }
}

void PlayerManager::Update()
{
    for(auto i = m_players.begin(); i != m_players.end(); ++i)
    {
        if((*i)->GetHealth() == 0)
        {
            (*i)->SetAlive(0);
            int lives = (*i)->GetLives();
            if(--lives < 0)
                lives = 0;
            (*i)->SetLives(lives);
        }

        if((*i)->GetAlive() == 0)
        {
            (*i)->SetX(-1);
            (*i)->SetY(-1);

            (*i)->SetHealth(100);
            (*i)->SetAlive(1);
        }

        if( ((*i)->GetLives() != 0) && !((*i)->IsLevelCompleted()) )
            (*i)->Update();
    }
}

Player* PlayerManager::GetPlayerById(int id)
{
    return m_players[id];
}

std::vector<Player*>* PlayerManager::GetPlayers()
{
    return &m_players;
}

bool PlayerManager::AreAllDead() const
{
    for(auto i = m_players.begin(); i != m_players.end(); ++i)
    {
        if((*i)->GetLives() != 0)
        {
            return false;
        }
    }
    return true;
}

bool PlayerManager::AreAllCompleted() const
{
    bool finished = false;
    for(auto i = m_players.begin(); i != m_players.end(); ++i)
    {
        if(!(*i)->IsLevelCompleted() && (*i)->GetLives() != 0)
        {
            return false;
        }
        else
        if((*i)->IsLevelCompleted())
            finished = true;
    }
    return finished;

}

