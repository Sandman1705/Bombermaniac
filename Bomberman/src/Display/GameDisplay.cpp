#include "Display/GameDisplay.h"
#include "Display/PauseDisplay.h"
#include "System/SystemTimer.h"

#include "Utility/Relay.h"
#include "Manager/Map.h"
#include "Manager/BombManager.h"
#include "Manager/ExplosionManager.h"
#include "Manager/PlayerManager.h"
#include "Manager/EnemyManager.h"

GameDisplay::GameDisplay(SDL_Texture* texture,
                         SDL_Renderer* renderer,
                         unsigned int window_width,
                         unsigned int window_height,
                         unsigned int current_level,
                         unsigned int number_of_screen_elements)
    : Display(),
      m_texture(texture),
      m_renderer(renderer),
      m_window_width(window_width),
      m_window_height(window_height),
      m_current_level(current_level),
      m_level_completed(false)
{
    m_display_elements.reserve(number_of_screen_elements);
}

GameDisplay::~GameDisplay()
{
    for (auto i = m_display_elements.begin(); i != m_display_elements.end(); ++i)
    {
        delete (*i);
    }
    m_display_elements.clear();
}

void GameDisplay::AddDisplayElement(DisplayElement* display_element)
{
    m_display_elements.push_back(display_element);
}

void GameDisplay::Init()
{
    unsigned int tile_size = 44;
    m_relay = new Relay();
#ifdef _WIN32
    Map* level = new Map("resources\\levels\\level2.txt", m_texture, tile_size);
#else // LINUX
    Map* level = new Map("resources/levels/level2.txt", m_texture, tile_size);
#endif
    ExplosionManager* explosion_manager = new ExplosionManager(m_texture, tile_size);
    BombManager* bomb_manager = new BombManager(m_texture, tile_size, m_relay);
    PlayerManager* player_manager = new PlayerManager("resources/levels/player2.txt", m_texture, tile_size, m_relay, m_keyboard_input);
    player_manager->GetPlayers()->back()->SetKeycodes(SDLK_w, SDLK_s, SDLK_a, SDLK_d, SDLK_g);
    EnemyManager* enemy_manager = new EnemyManager("resources/levels/enemy2.txt", m_texture, tile_size, m_relay);

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

void GameDisplay::Enter(int mode)
{
    SystemTimer::Instance()->Unpause();
    m_leave_next = false;
    if (mode == 0)
    {
        m_leave_previous = true;
    }
    else
    {
        m_leave_previous = false;
    }
}

void GameDisplay::Leave()
{
    SystemTimer::Instance()->Pause();
}

int GameDisplay::Destroy()
{
    for (auto i = m_display_elements.begin(); i != m_display_elements.end(); ++i)
    {
        delete (*i);
    }
    m_display_elements.clear();
    if (m_level_completed)
        return ++m_current_level;
    else
        return 0;
}

void GameDisplay::Update()
{
    if (m_keyboard_input->IsKeyOn(SDLK_ESCAPE))
    {
        m_leave_next = true;
        m_next_display = new PauseDisplay(m_renderer, m_window_width, m_window_height, this);
    }
    else
    {
        for (auto i = m_display_elements.begin(); i != m_display_elements.end(); ++i)
        {
            (*i)->Update();
        }
    }
}

void GameDisplay::Draw(SDL_Renderer* renderer) const
{
    for (auto i = m_display_elements.cbegin(); i != m_display_elements.cend(); ++i)
    {
        (*i)->Draw(renderer);
    }
}
