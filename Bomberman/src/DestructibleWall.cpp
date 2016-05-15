#include "DestructibleWall.h"

DestructibleWall::DestructibleWall(SDL_Texture *texture, SDL_Rect SrcR)
    : MapObject(MapObject::DESTRUCTIBLE_WALL,texture,SrcR), m_integrity(S_MAX_INTEGRITY)
{
}

bool DestructibleWall::IsDestroyed() const
{
    if (m_integrity <= 0)
        return true;
    else
        return false;
}

void DestructibleWall::DecreaseIntegrity(int value)
{
    m_integrity -= value;
    if (m_integrity <=50)
        m_SrcR.y += 64;
}
