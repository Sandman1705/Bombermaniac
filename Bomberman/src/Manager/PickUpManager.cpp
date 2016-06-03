#include "Manager\PickUpManager.h"

//#define DEBUG_OUTPUT_PICKUP_MANAGER

#ifdef DEBUG_OUTPUT_PICKUP_MANAGER
#include <iostream>
#endif // DEBUG_OUTPUT_PICKUP_MANAGER

PickUpManager::PickUpManager(SDL_Texture* texture,
                             unsigned int tile_size,
                             Relay* relay)
    : DisplayElement(texture),
      m_tile_size(tile_size),
      m_draw_size(tile_size*3/4),
      m_relay(relay)
{
}

PickUpManager::~PickUpManager()
{
    for(auto i = m_pickups.begin(); i != m_pickups.end(); ++i)
    {
        delete (*i);
        #ifdef DEBUG_OUTPUT_PICKUP_MANAGER
        std::cout << "PickUp deleted" << std::endl;
        #endif // DEBUG_OUTPUT_PICKUP_MANAGER
    }
}

void PickUpManager::AddPickUp(PickUp* pickup)
{
    m_pickups.push_back(pickup);
}

void PickUpManager::MakePickUp(PickUp::PickUpType type, int x, int y, int value)
{
    #ifdef DEBUG_OUTPUT_PICKUP_MANAGER
    std::cout << "Making pickup with value" << value << std::endl;
    #endif // DEBUG_OUTPUT_PICKUP_MANAGER
    PickUp* pickup = new PickUp(m_texture,type,value,x,y,m_draw_size);
    AddPickUp(pickup);
}

void PickUpManager::Update()
{
    for(auto i = m_pickups.begin(); i != m_pickups.end();)
    {
        if((*i)->IsUsed())
        {
            delete (*i);
            i = m_pickups.erase(i);
        }
        else
            ++i;
    }
}

void PickUpManager::Draw(SDL_Renderer* renderer) const
{
    for(auto i = m_pickups.begin(); i != m_pickups.end(); ++i)
    {
        (*i)->Draw(renderer);
    }
}

std::list<PickUp*>* PickUpManager::GetPickUps()
{
    return &m_pickups;
}
