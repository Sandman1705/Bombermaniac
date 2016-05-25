#ifndef PICKUPMANAGER_H
#define PICKUPMANAGER_H

#include "Display/DisplayElement.h"
#include "Utility/Relay.h"
#include "Entity/PickUp.h"
#include <list>

class PickUpManager : public DisplayElement
{
    public:
        PickUpManager(SDL_Texture* texture, unsigned int tile_size, Relay* relay);
        ~PickUpManager();

        void AddPickUp(PickUp* pickup);
        void MakePickUp(PickUp::PickUpType type, int x, int y, int value = 0);

        virtual void Update();
        virtual void Draw(SDL_Renderer* renderer) const;
    protected:

    private:
        std::list<PickUp*>      m_pickups;
        unsigned int            m_tile_size;
        unsigned int            m_draw_size;
        Relay*                  m_relay;
};

#endif // PICKUPMANAGER_H
