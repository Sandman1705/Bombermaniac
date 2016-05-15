#ifndef DESTRUCTIBLEWALL_H
#define DESTRUCTIBLEWALL_H

#include "MapObject.h"

class DestructibleWall : public MapObject
{
    public:
        DestructibleWall(SDL_Texture *texture, SDL_Rect SrcR);

        bool IsDestroyed();
        void DecreaseIntegrity(int value);

        static const int S_MAX_INTEGRITY = 100;

    protected:


    private:
        int     m_integrity;

};

#endif // DESTRUCTIBLEWALL_H
