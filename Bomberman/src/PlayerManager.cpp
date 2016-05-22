#include "PlayerManager.h"
#include "Destroyer.h"
#include <fstream>
PlayerManager::PlayerManager(std::string path_to_file, SDL_Texture* texture, unsigned int tile_size, Relay *relay,
               KeyboardInput *keyboard_input)
    : DisplayElement(texture)
{
    m_tile_size = tile_size;
    m_relay = relay;
    m_keyboard_input = keyboard_input;
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
    Player *player = new Player(m_texture, m_tile_size, m_relay, m_keyboard_input, player_id, x, y);
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

void PlayerManager::Draw(SDL_Renderer* renderer) const
{
    for(auto i = m_players.begin(); i != m_players.end(); ++i)
    {
        //Draw number of lives--------------------------------
        SDL_Rect SrcR;
        SDL_Rect DestR;

        unsigned int SHAPE_SIZE_x = 12;
        unsigned int SHAPE_SIZE_y = 17;

        unsigned int source_x = 200;
        unsigned int source_y = 174;

        SrcR.y = source_y;
        SrcR.w = SHAPE_SIZE_x;
        SrcR.h = SHAPE_SIZE_y;

        switch((*i)->GetLives())
        {
            case 0:
                SrcR.x = ((*i)->GetLives())*SHAPE_SIZE_x + source_x;
            break;

            case 1:
                SrcR.x = ((*i)->GetLives())*SHAPE_SIZE_x + source_x;
            break;

            case 2:
                SrcR.x = ((*i)->GetLives())*SHAPE_SIZE_x + source_x;
            break;

            case 3:
                SrcR.x = ((*i)->GetLives())*SHAPE_SIZE_x + source_x;
            break;
        }

        DestR.x = 0 + (*i)->GetID()*2*m_tile_size;
        DestR.y = 0;
        DestR.w = m_tile_size;
        DestR.h = m_tile_size;

        SDL_RenderCopy(renderer, m_texture, &SrcR, &DestR);

        //----------------------------------------------------

        //main condition
        if((*i)->GetAlive() != 0)
        {
            (*i)->Draw(renderer);
        }
    }
}

void PlayerManager::Update()
{
    for(auto i = m_players.begin(); i != m_players.end(); ++i)
    {
        if((*i)->GetHealth() == 0 && (*i)->GetAlive())
        {
            (*i)->SetAlive(0);
            int lives = (*i)->GetLives();
            if(--lives < 0)
                lives = 3;
            (*i)->SetLives(lives);
            m_timer.ResetTimer();
        }

        if((*i)->GetAlive() == 0 && m_timer.GetTimeElapsed() >= 2000)
        {
            (*i)->SetAlive(1);
            (*i)->SetHealth(100);
        }

        (*i)->Update();
    }
}

std::list<Player*>* PlayerManager::GetPlayers()
{
    return &m_players;
}
