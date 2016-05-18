#include "GameDisplay.h"
#include "ScreenTimer.h"

#include "Relay.h"
#include "Map.h"
#include "BombManager.h"
#include "ExplosionManager.h"
#include "PlayerManager.h"
#include "EnemyManager.h"

GameDisplay::GameDisplay(SDL_Texture* texture,
                         KeyboardInput* keyboard_input,
                         unsigned int number_of_screen_elements = 1)
    : Display(keyboard_input), m_texture(texture)
{
    m_display_elements.reserve(number_of_screen_elements);
}

GameDisplay::~GameDisplay()
{
    for (auto i = m_display_elements.begin(); i != m_display_elements.end(); ++i)
    {
        delete (*i);
    }
}

void GameDisplay::AddDisplayElement(DisplayElement* display_element)
{
    m_display_elements.push_back(display_element);
}

void GameDisplay::Init()
{
    unsigned int tile_size = 44;
    m_relay = new Relay();

    Map* level = new Map("resources\\levels\\level2.txt", m_texture, tile_size);
    ExplosionManager* explosion_manager = new ExplosionManager(m_texture, tile_size);
    BombManager* bomb_manager = new BombManager(m_texture, tile_size, m_relay);
    PlayerManager* player_manager = new PlayerManager(m_texture, tile_size, m_relay, m_keyboard_input);
    player_manager->MakePlayer();
    EnemyManager* enemy_manager = new EnemyManager(m_texture, tile_size, m_relay);

    enemy_manager->MakeEnemy(5*tile_size);
    enemy_manager->MakeEnemy(0, 10*tile_size);
    enemy_manager->MakeEnemy(10*tile_size);
    enemy_manager->MakeEnemy(8*tile_size, 8*tile_size);

    m_relay->SetExplosionManager(explosion_manager);
    m_relay->SetBombManager(bomb_manager);
    m_relay->SetPlayerManager(player_manager);
    m_relay->SetEnemyManager(enemy_manager);
    m_relay->SetMap(level);

    AddDisplayElement(level);
    AddDisplayElement(bomb_manager);
    AddDisplayElement(player_manager);
    AddDisplayElement(enemy_manager);
    AddDisplayElement(explosion_manager);
}

void GameDisplay::Enter()
{
    ScreenTimer::Instance()->Unpause();
}

void GameDisplay::Leave()
{
    ScreenTimer::Instance()->Pause();
}

void GameDisplay::Destroy()
{

}

void GameDisplay::Update()
{
    for (auto i = m_display_elements.begin(); i != m_display_elements.end(); ++i)
    {
        (*i)->Update();
    }
}

void GameDisplay::Draw(SDL_Renderer* renderer) const
{
    for (auto i = m_display_elements.cbegin(); i != m_display_elements.cend(); ++i)
    {
        (*i)->Draw(renderer);
    }
}
